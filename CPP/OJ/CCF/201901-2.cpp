/*
    题意：小明种苹果，苹果成环形围绕，小明定期进行疏果操作，输入为0或负数；同时还会进行重新统计次数，记录苹果自然掉落
          输出1.疏果后所有剩余苹果数量T；2.掉落的棵树D；3.相邻连续三棵掉落的组数E
    注意：可能会进行多次统计，计算D要在外层进行。
*/
#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1010;

int main()
{
    int n,apple[N]={0},drop[N]={0};
    int D=0,E=0;
    long long T=0;

    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int loop,num;
        cin >> loop >> apple[i];
        for(int j=2;j<=loop;j++)
        {
            scanf("%d",&num);
            if(num > 0)
            {
                if(apple[i] > num) 
                {
                    drop[i] = 1;
                    apple[i] = num;
                }
            }
            else apple[i] += num;
        } 

        T += apple[i];
        if(drop[i] == 1) D++;
    }

    drop[0] = drop[n];
    drop[n+1] = drop[1];

    for(int i=1;i<=n;i++)
    {
        if(drop[i-1] && drop[i] && drop[i+1]) E++; 
    }

    printf("%d %d %d\n",T,D,E);

    return 0;
}
