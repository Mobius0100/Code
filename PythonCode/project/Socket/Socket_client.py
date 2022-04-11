import socket
import time

HOST = 'localhost'
PORT = 21567
BUFFSIZ = 1024
ADDR = (HOST, PORT)

tcpcli_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
tcpcli_sock.connect(ADDR)   # 执行三次握手，创建TCP连接

while True:
    data = input('> ')
    if not data:
        break
    tcpcli_sock.send(data.encode('utf-8'))
    data = tcpcli_sock.recv(BUFFSIZ)
    if not data:
        break
    print(data.decode('utf-8'))

tcpcli_sock.close()