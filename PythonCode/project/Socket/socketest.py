import socket

HOST = '127.0.0.1'
PORT = 49869

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST,PORT))
data = "HELLO!"
while data:
    s.sendall(data.encode('utf-8'))
    data = s.recv(512)
    print("获取服务器信息：\n", data.decode('utf-8'))
    data = input('请输入信息：\n')
s.close()