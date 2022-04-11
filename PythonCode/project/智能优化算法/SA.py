import random
import numpy as np
import math

num_city=31#城市总数
initial_t=120#初始温度
lowest_t=0.001#最低温度
M=150#当连续多次都不接受新的状态，开始改变温度
iteration=500#设置迭代次数



location=np.loadtxt('city_data.txt')

coordinate = [[1304, 2312], [3639, 1315], [4177, 2244], [3712, 1399], [3488, 1535], [3326, 1556],
                [3238, 1229], [4196, 1004], [4312, 790], [4386, 570], [3007, 1970], [2562, 1756],
                [2788, 1491], [2381, 1676], [1332, 695], [3715, 1678], [3918, 2179], [4061, 2370],
                [3780, 2212], [3676, 2578], [4029, 2838], [4263, 2931], [3429, 1908], [3507, 2367],
                [3394, 2643], [3439, 3201], [2935, 3240], [3140, 3550], [2545, 2357], [2778, 2826], [2370, 2975]
                ]

#==========================================
#对称矩阵，两个城市之间的距离
def distance_p2p_mat():
    dis_mat=[]
    for i in range(num_city):
        dis_mat_each=[]
        for j in range(num_city):
            #dis=math.sqrt(pow(location[i][0]-location[j][0],2)+pow(location[i][1]-location[j][1],2))
            dis=math.sqrt(pow(coordinate[i][0] - coordinate[j][0],2)+pow(coordinate[i][1]-coordinate[j][1],2))
            dis_mat_each.append(dis)
        dis_mat.append(dis_mat_each)
    return dis_mat

#计算所有路径对应的距离
def cal_newpath(dis_mat,path):
    dis=0
    for j in range(num_city-1):
        dis=dis_mat[path[j]][path[j+1]]+dis
    dis=dis_mat[path[num_city-1]][path[0]]+dis#回家
    return dis

#==========================================
#点对点距离矩阵
dis_mat=distance_p2p_mat()
#初始路径
path=list(range(num_city))
#初始距离
dis=cal_newpath(dis_mat,path)
#初始温度
t_current=initial_t

while (t_current>lowest_t):#外循环，改变温度
    count_m=0#M的计数
    count_iter=0#迭代次数计数
    while (count_m<M and count_iter<iteration):#内循环，连续多次不接受新的状态或者是迭代多次,跳出内循环        
        i=0
        j=0
        while(i==j):#防止随机了同一城市
            i=random.randint(1,num_city-1)
            j=random.randint(1,num_city-1)
        path_new=path.copy()
        path_new[i],path_new[j]=path_new[j],path_new[i]#任意交换两个城市的位置,产生新解
        #计算新解的距离
        dis_new=cal_newpath(dis_mat,path_new)
        #求差
        dis_delta=dis_new-dis
        #取0-1浮点随机数
        rand=random.random()
        #计算指数函数的值
        exp_d=math.exp(-dis_delta/t_current)
        #选择
        if dis_delta<0:
            path=path_new
            dis=dis_new
        elif exp_d>rand:
            path=path_new
            dis=dis_new    
        else:
            count_m=count_m+1
        count_iter=count_iter+1
    t_current=0.99*t_current#改变温度
#外循环结束
dis_min=dis
path_min=path
print('最短距离：',dis_min)
print('最短路径：',path_min)





