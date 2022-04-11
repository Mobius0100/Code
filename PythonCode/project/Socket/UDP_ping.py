from socket import *
import time

def ping(host='localhost'):
    HOST = host
    PORT = 12000
    BUFFSIZ = 2048
    ADDR = (HOST, PORT)

    udp_clients = socket(AF_INET, SOCK_DGRAM) # 区别于TCP
    udp_clients.settimeout(1)    # 设置超时时间用于处理超时异常

    n = 5
    max = -1
    min = 1000
    sum = 0.0
    cnt = 0

    pack = n
    while pack:
        udp_clients.sendto('ping'.encode(), ADDR)

        try:
            T1 = time.perf_counter()
            rev_data, addr = udp_clients.recvfrom(BUFFSIZ)
            T2 = time.perf_counter()
            T = (T2-T1) * 1000
            if(T > max):
                max = T
            if(T < min):
                min = T
            
            sum = sum + T
            print('来自 {0} 的回复： {1} 时延RTT={2:.3f}ms'.format(addr[0], rev_data.decode(), T))
        except:
            print('Timeout Package Lost...')
            cnt = cnt + 1

        pack = pack-1

    print('\nTest over!')
    print('已发送 = {0}, 已接受 = {1}, 丢失 = {2} ({3:.2%} 丢失)'.format(n, n-cnt, cnt, cnt/n))
    print('最短时间 = {0:.3f}ms, 最长时间 = {1:.3f}ms, 平均时间 = {2:.3f}ms '.format(min, max, sum/5))
    udp_clients.close()

ping('127.0.0.1')