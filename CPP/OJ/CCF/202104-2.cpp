/*
    ：邻域均值；计算图片中像素点的邻域是否在较暗区域
                定义：像素点四周r的范围内元素的平均值小于阈值t，则该点在较暗区域
                用二维前缀和来预先计算元素和，减少时间复杂度，否则会超时
                注意：边界范围
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 610;
int num[N][N] = {0};
int flag[N][N] = {0};

int main()
{
    int n,L,r,t,cnt=0;
    cin >> n >> L >> r >> t;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> num[i][j];
            flag[i][j] = flag[i-1][j] + flag[i][j-1] - flag[i-1][j-1] + num[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            // 边界没有想清楚
            // int a = j-r;
            // int b = i-r;
            // int c = i+r;
            // int d = j+r;
            // if(a < 1) a = 1;
            // if(b < 1) b = 1;
            // if(c > n) c = n;
            // if(d > n) d = n;
            // int cout = (c-b+1)*(d-a+1);
            // double sum = flag[c][d] - flag[c][a] - flag[b][d] + flag[b][a];
            // sum = sum / (cout*1.0);
            // if(sum <= t) cnt++;
            int left = max(j-r,1),right = min(j+r,n);
            int up = max(i-r,1), down = min(i+r,n);
            int sum = flag[down][right] - flag[down][left - 1] - flag[up-1][right] + flag[up-1][left-1];
            if(sum <= (down - up + 1) * (right - left + 1) * t) cnt++;


        }
    }

    cout << cnt << endl;
    return 0;
}
