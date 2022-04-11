import sys
import socket
import threading

BUFFSIZ = 1024

class RecvThread(threading.Thread):
    """ 接受消息线程 """

    def __init__(self, sock):
        super().__init__()
        self.daemon = True
        self.sock = sock
    
    def run(self):
        while True:
            msg = self.sock.recv(BUFFSIZ)
            print(msg.decode('utf-8'))

def main(host='localhost', port=21567):
    addr = (host, port)
    tcpcli_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    tcpcli_sock.connect(addr)

    tcpcli_sock.send(b'initNick')
    nick = input('请输入昵称：')
    tcpcli_sock.send(nick.encode('utf-8'))

    recv_thread = RecvThread(tcpcli_sock)
    recv_thread.start()

    while True:
        msg = input('>')
        msg = msg.encode('utf-8')
        tcpcli_sock.send(msg)

        if msg == b'exit':
            tcpcli_sock.close()
            break


if __name__ == "__main__":
    main()