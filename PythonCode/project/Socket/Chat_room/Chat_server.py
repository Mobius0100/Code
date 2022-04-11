import socket
import threading
from time import ctime
import time
from tkinter.constants import S

BUFFSIZ = 1024
HOST = ''
PORT = 21567
ADDR = (HOST, PORT)

class ClientThread(threading.Thread):
    def __init__(self, sock, addr, conn_pool, pool_lock, nickname):
        super().__init__()
        self.daemon = True
        self.sock = sock
        self.addr = addr
        self.conn_pool = conn_pool
        self.pool_lock = pool_lock
        self.nickname = nickname
        self.time = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())

    def broadcast(self, msg):
        """ 广播消息 """
        for addr, sock in self.conn_pool.items():
            if addr != self.addr:
                sock.send(b'[' + self.time.encode('utf-8') + b']' + f'{self.nickname}: '.encode('utf-8') + msg)
                # sock.send(b'[' + bytes(ctime(), 'utf-8') + b'] '+ f'{self.nickname} :'.encode('utf-8') + msg)

    def exit(self):
        """ 客户端退出 """
        print(f'{self.addr}断开连接！')
        self.broadcast('断开连接'.encode('utf-8'))
        self.sock.close()
        with self.pool_lock:
            self.conn_pool.pop(self.addr)
    
    def run(self):
        """ 线程主函数 """
        while True:
            msg = self.sock.recv(BUFFSIZ)
            print('[', self.time , ']', f'来自{self.addr} {self.nickname}的消息:',  msg.decode('utf-8'))
            if msg in [b'#@exit']:
                self.exit()
                break
            else:
                self.broadcast(msg)

def main():
    """ 主程序 """
    sock = socket.socket()
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    sock.bind(ADDR)
    sock.listen(100)
    print(f'开始监听：{ADDR}')

    conn_pool = {}
    pool_lock = threading.Lock()

    while True:

        cli_sock, cli_addr = sock.accept() # 连接套接字
        print(f'#===========来自{cli_addr}的连接============#')
        
        nick = cli_sock.recv(BUFFSIZ).decode('utf-8')
        cli_sock.send(b'Connection successful~')

        with pool_lock:
            conn_pool[cli_addr] = cli_sock
        cli_thread = ClientThread(cli_sock, cli_addr, conn_pool, pool_lock, nick)
        cli_thread.start()

if __name__ == "__main__":
    main()
    
