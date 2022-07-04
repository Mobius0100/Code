/*
    :消除游戏；每行每列中，有连续3个以上相同的数，被消除。输出被消除后的结果
    ：对行和列分别扫描，若有3个以上的数相同，将其标记，最后根据标记结果将该数字置零，然后输出；
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    int num[40][40] = {0};
    int flag[40][40] = {0};

    cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin >> num[i][j];
    }
    
    for(int i=0;i<n;i++){        //行扫描
        for(int j=1;j<m-1;j++){
            if(num[i][j] == num[i][j-1] && num[i][j] == num[i][j+1]){
                flag[i][j] = 1;
                flag[i][j-1] = 1;
                flag[i][j+1] = 1;
            }
        }
    }

    for(int i=0;i<m;i++){     //列扫描
        for(int j=1;j<n-1;j++){
            if(num[j][i] == num[j-1][i] && num[j][i] == num[j+1][i]){
                flag[j][i] = 1;
                flag[j-1][i] = 1;
                flag[j+1][i] = 1;
            }
        }
    }

    for(int i=0;i<n;i++){    // 置零
        for(int j=0;j<m;j++){
            if(flag[i][j] == 1) num[i][j] = 0;
        }
    }

    for(int i=0;i<n;i++){       //输出
        for(int j=0;j<m;j++) printf("%d ",num[i][j]);
        printf("\n");
    }
    return 0;
}
