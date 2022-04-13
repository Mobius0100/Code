import random
import numpy as np
from math import e
from math import exp
import matplotlib.pyplot as plt
#31个城市的坐标
city_loc = [(1304,2312),(3639,1315),(4177,2244),(3712,1399),(3488,1535),
                 (3326,1556),(3238,1229),(4196,1004),(4312,790),(4380,570),
                 (3007,1970),(2562,1756),(2788,1491),(2381,1676),(1332,695),
                 (3715,1678),(3918,2179),(4061,2370),(3780,2212),(3676,2578),
                 (4029,2838),(4263,2931),(3429,1908),(3507,2367),(3394,2643),
                 (3439,3201),(2935,3240),(3140,3550),(2545,2357),(2778,2826),(2370,2975)]

T0 = 5000 #初始温度
T_end = 15 #结束温度
q = 0.98 #每次退火的比例
L = 1000 #每个温度的迭代次数

#两个城市的距离
def dist(a, b):
    x1 = city_loc[a][0]
    x2 = city_loc[b][0]
    y1 = city_loc[a][1]
    y2 = city_loc[b][1]
    distance = ((x2 - x1)**2 + (y2 - y1)**2)**0.5
    return distance
#路程总长
def totaldistance(a):
    value = 0
    for j in range(30):
        value += dist(a[j], a[j + 1])
    value += dist(a[30], a[0])
    return value

#初始化一个解 [0,1,2,3..30]
def init_ans():
    ans = []
    for i in range(31):
        ans.append(i)
    return ans
#产生新解
def creat_new(ans_before):
    ans_after = []
    for i in range(len(ans_before)):
        ans_after.append(ans_before[i])
    cuta = random.randint(0,30)
    cutb = random.randint(0,30)
    ans_after[cuta], ans_after[cutb] = ans_after[cutb], ans_after[cuta]
    return ans_after

if __name__ == '__main__':
    ans0 =init_ans()
    T = T0
    cnt = 0
    trend = []
    while T > T_end:
        for i in range(L):
            newans = creat_new(ans0)
            old_dist = totaldistance(ans0)
            new_dist = totaldistance(newans)
            df = new_dist - old_dist
            if df >= 0:
                rand = random.uniform(0,1)
                if rand < 1/(exp(df / T)):
                    ans0 = newans
            else:
                ans0 = newans
        T = T * q
        cnt += 1
        now_dist = totaldistance(ans0)
        trend.append(now_dist)
        print(cnt,"次降温，温度为：",T," 路程长度为：", now_dist)
    distance = totaldistance(ans0)
    print(distance, ans0)
    plt.plot(trend)
    plt.rcParams['font.sans-serif']=['SimHei'] #用来正常显示中文标签
    plt.rcParams['axes.unicode_minus'] = False #用来正常显示负号
    plt.title('SA算法解决TSP问题')
    plt.xlabel('迭代次数')
    plt.ylabel('路程长度')
    plt.show()


