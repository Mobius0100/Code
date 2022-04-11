from socket import *
from time import ctime

HOST = ''
PORT = 21567
BUFFSIZ = 1024
ADDR = (HOST, PORT)

# TCP服务器套接字使用步骤：创建，绑定，监听
tcpsersock = socket(AF_INET, SOCK_STREAM)  # （欢迎套接字）
tcpsersock.bind(ADDR)
tcpsersock.listen(5)  # 请求连接最大数目5

while True:
    print("Waiting For Connection...")
    # tcpcli_sock 为新套接字(连接套接字)，区别于tcpsersock
    tcpcli_sock, addr = tcpsersock.accept()     
    print('...Connected from:', addr)

    while True:
        data = tcpcli_sock.recv(BUFFSIZ)
        if not data:
            break
        print("Recive Message From ",addr, "\n" , data.decode('utf-8'))
        # tcpcli_sock.send('[%s] %s' % (bytes(ctime(), 'utf-8'), data))  ## python2的风格，书搞错了
        data = input("Reply:")
        tcpcli_sock.send(b'[' + bytes(ctime(), 'utf-8') + b'] ' + data.encode('utf-8') )
    tcpcli_sock.close()
tcpsersock.close()