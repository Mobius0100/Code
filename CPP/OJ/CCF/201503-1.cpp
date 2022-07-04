/*
    :图像旋转，给定一组二维矩阵当作图像，将其逆时针旋转90度后输出
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1100;
int num[N][N] = {0};

int main()
{
    int m,n;
    
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> num[i][j];
        }
    }

    for(int i=m-1;i>=0;i--){
        for(int j=0;j<n;j++){
            printf("%d ",num[j][i]);
        }
        cout << endl;
    }
    return 0;
}
