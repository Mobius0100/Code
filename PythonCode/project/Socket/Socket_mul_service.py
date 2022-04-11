from socket import *
from time import ctime
import threading

HOST = ''
PORT = 21567
BUFFSIZ = 1024
ADDR = (HOST, PORT)

def messgae_process(client_sock, addr):
    print('Link from ', addr, '\n')
    while True:
        data = client_sock.recv(BUFFSIZ)
        if not data:
            break
        print("Recive Message From ",addr, "\n" , data.decode('utf-8'))
        data = 'Hello!'
        client_sock.send(b'[' + bytes(ctime(), 'utf-8') + b'] ' + data.encode('utf-8') )
    client_sock.close()    
    print('Link from ', addr , 'is over!\n')

# TCP服务器套接字使用步骤：创建，绑定，监听
tcpsersock = socket(AF_INET, SOCK_STREAM)  # （欢迎套接字）
tcpsersock.bind(ADDR)
tcpsersock.listen(5)  # 请求连接最大数目5

while True:
    print("Waiting For Connection...")
    # tcpcli_sock 为新套接字(连接套接字)，区别于tcpsersock

    tcpcli_sock, addr = tcpsersock.accept()     
    print('...Connected from:', addr)

    t = threading.Thread(target=messgae_process, args=(tcpcli_sock, addr))
    t.start()


