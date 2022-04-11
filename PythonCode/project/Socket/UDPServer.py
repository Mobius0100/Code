from socket import *

HOST = ''
PORT = 12000
BUFFSIZ = 2048
ADDR = (HOST, PORT)

# UDP服务器套接字使用步骤：创建，绑定
udp_servers = socket(AF_INET, SOCK_DGRAM) 
udp_servers.bind(ADDR)

print('Server is ready to receive')

while True:
    message, cliaddr = udp_servers.recvfrom(BUFFSIZ)
    print("Message Received-------\n" + str(cliaddr))
    modi_message = message.decode().upper()
    udp_servers.sendto(modi_message.encode(), cliaddr)  # 发送需要带地址