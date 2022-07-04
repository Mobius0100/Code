/*
    :灰度直方图；统计给定的图片矩阵中每个像素的个数
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,L,k;
    cin >> n >> m >> L;

    int ans[L] = {0};

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >>  k;
            ans[k]++;
        }
    }

    for(int i=0;i<L;i++){
        cout << ans[i] << " ";
    }

    return 0;
}
