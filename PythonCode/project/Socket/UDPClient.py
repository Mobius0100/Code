from socket import *

HOST = 'localhost'
PORT = 12000
BUFFSIZ = 2048
ADDR = (HOST, PORT)

udp_clients = socket(AF_INET, SOCK_DGRAM) # 区别于TCP
#udp_clients.bind(('',5432))
message = input('>>>>>>>>\n')

# UDP发送消息方法
udp_clients.sendto(message.encode(), ADDR)
# UDP接受消息方法
rev_data, addr = udp_clients.recvfrom(BUFFSIZ)

print(rev_data.decode())
udp_clients.close()