/*
    :俄罗斯方块；给定初始状态和方块图案，以及下落位置，问最终图形
    思路:以方块为单位，模拟下落；比较方块中每一格与板上初始状态
         如果两者都为1，说明发生碰撞，往上移一行即为最终图案
    注意：下标以1开始，可直接加下落位置k
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    int pict[4][4] = {0};
    int mp[20][15] = {0};

    for(int i=1;i<=15;i++){
        for(int j=1;j<=10;j++) cin >> mp[i][j];
    }
    for(int i=1;i<=10;i++){
        mp[16][i] = 1;
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++) cin >> pict[i][j];
    }
    cin >> k;

    bool over = false;
    int i;
    for(i=0;i<=15;i++){
        for(int a=0;a<4;a++){
            for(int b=0;b<4;b++){
                if(pict[a][b] && mp[i+a][b+k]){
                    over = true;
                }
            }
            
        }

        if(over) break;
    }

    for(int a=0;a<4;a++){
        for(int b=0;b<4;b++){
            mp[i+a-1][b+k] += pict[a][b];
        }
    }

    for(int i=1;i<=15;i++){
        for(int j=1;j<=10;j++){
            printf("%d ",mp[i][j]);
        }
        printf("\n");
    }
    return 0;
}
