#include<bits/stdc++.h>
using namespace std;
#define rand(a,b) ((rand()%(b-a))+a)
const int INF=INT_MAX;
const int K=30;//小型搜索的次数
const int ITERATIONS=100 ;//小型搜索中的迭代次数
const int TABU_SIZE=20;//禁忌长度
const int SWAPSIZE=5;//交换数目 ，理解为候选集，此代码中没有用到

int city[60][2];//记录城市坐标
double adj[60][60];//记录城市之间的距离
int nowPath[60];//当前路径
int finalBestPath[60];//最优路径
int TabuList[2000][3];//第一维度 邻域id 第二维度 0:start 1:end 2.tabu
//原文件里还有个dis但是个人觉得没有必要 因为没有复用到
//在最大规模为60的问题中 邻域数量最大为60*59/2 给到2000是足够的

int coordinate[100] = {1304, 2312, 3639, 1315, 4177, 2244, 3712, 1399, 3488, 1535, 3326, 1556,
                3238, 1229, 4196, 1004, 4312, 790, 4386, 570, 3007, 1970, 2562, 1756,
                2788, 1491, 2381, 1676, 1332, 695, 3715, 1678, 3918, 2179, 4061, 2370,
                3780, 2212, 3676, 2578, 4029, 2838, 4263, 2931, 3429, 1908, 3507, 2367,
                3394, 2643, 3439, 3201, 2935, 3240, 3140, 3550, 2545, 2357, 2778, 2826, 2370, 2975
};

void readAndInit(int n);
void getRandomOrder(int path[],int n);//将path初始化为随机序列 值域[0,n)
void TabuSearch(int n);//禁忌搜索主体
double smallSearch(int n);//小型搜索
double getPathValue(int path[],int n);//获取给定路径的数值


int main(){
    int n=31;
     readAndInit(n);//读入数据以及举例 数据初始化
     TabuSearch(n);
}

void readAndInit(int n){
    for(int i=0;i<n*2;i++)
        city[i/2][i%2] = coordinate[i];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                adj[i][j]=sqrt((city[i][0]-city[j][0])*(city[i][0]-city[j][0])+(city[i][1]-city[j][1])*(city[i][1]-city[j][1]));
}

void TabuSearch(int n){
    double finalDis=INF;
    //初始化禁忌表
    int now=0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++){
            TabuList[now][0]=i;
            TabuList[now][1]=j;
            TabuList[now][2]=0;
            now++;
        }
    //
    for(int i=0;i<K;i++){//值得注意 每次搜索禁忌表是共享的 也就是新的小搜索不会重置禁忌表
        double smallSearchDis=smallSearch(n);
        if(finalDis>smallSearchDis){//如果此次小型搜索的最优解优于finalDis,则更新
            finalDis=smallSearchDis;
            memcpy(finalBestPath,nowPath,sizeof (nowPath));//路径复制
        }

    }
    //show
    cout<<"路线长度：" << finalDis<<endl;
    cout << "路线：";
    for(int i=0;i<n;i++)
        printf("->%d",finalBestPath[i]);
}

double smallSearch(int n){
    getRandomOrder(nowPath,n);
    double bestDis=getPathValue(nowPath,n);//初始化小型搜索最优解

    double pardon[2], curBest[2];//特赦最优解和搜索最优解
    pardon[0]=pardon[1]=curBest[0]=curBest[1]=INF;//初始化
    int LNum=n*(n-1)/2;//邻域数量
    for(int i=0;i<ITERATIONS;i++){//迭代
        for(int j=0;j<LNum;j++){//领域搜索
            swap(nowPath[TabuList[j][0]],nowPath[TabuList[j][1]]);
            double tmpDis=getPathValue(nowPath,n);
            if(TabuList[j][2]==0){//没有被禁忌
                if(tmpDis<curBest[1]){
                    curBest[0]=j;
                    curBest[1]=tmpDis;
                }
            }
            else{//被禁忌
                if(tmpDis<pardon[1]){
                    pardon[0]=j;
                    pardon[1]=tmpDis;
                }
            }
            swap(nowPath[TabuList[j][0]],nowPath[TabuList[j][1]]);
        }
        //邻域搜索结束
        //判断特设最优解是否满足特赦条件
        //第一个条件对应领域全被禁忌，在邻域数量大于禁忌长度时不可能出现
        //第二个条件似乎存疑，此刻curBest并没有更新到bestDis上，
        //如果此时curBest比pardon更优，则curBest无法被更新，可能这样是增加搜索前面的可能性？
        //另一方面如果第二个条件成立 必然出现在另一次小型搜索过程中
        //因为重新搜索并没有重置禁忌表，但bestDis被重置，在同一次小型搜索中不可能满足第二个条件
        if(curBest[1] == INF || pardon[1] < bestDis){
            curBest[0]=pardon[0];
            curBest[1]=pardon[1];
        }
        //尝试更新 小型搜索的最优解bestDis
        if(curBest[1]<bestDis){
            bestDis=curBest[1];
            //交换位置
            swap(nowPath[TabuList[(int)curBest[0]][0]],nowPath[TabuList[(int)curBest[0]][1]]);
            //更新禁忌表 
            TabuList[(int)curBest[0]][2]=TABU_SIZE;
            for(int j=0;j<LNum;j++)
                if(TabuList[j][2]>0)
                    TabuList[j][2]--;
        }
        //随机性可能导致某一次搜索永远在某一个较高点，附近邻域都没有比他大的，即便是禁忌表特赦也没有用

    }
    // cout << bestDis << endl;
    return bestDis;
}

void getRandomOrder(int path[],int n){
    //srand(time(0));//保证结果可复现 注释此句
    for(int i=0;i<n;i++)
        path[i]=i;
    for(int i=0;i<n;i++)
        swap(path[i],path[rand(i,n)]);
}

double getPathValue(int path[],int n){
    double value=adj[path[n-1]][path[0]];
    for(int i=0;i<n-1;i++)
        value+=adj[path[i]][path[i+1]];
     return value;
}

