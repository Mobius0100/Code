/*
    :画图，给定矩形对角坐标，将矩形涂色，问共有多少格子被涂色
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int main()
{
    int n,cnt=0;
    int x1,x2,y1,y2;
    int rect[N][N] = {0};
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int a=x1;a<x2;a++){
            for(int b=y1;b<y2;b++){
                if(rect[a][b] != 1){
                    cnt++;
                    rect[a][b] = 1; 
                }
            }
        }
    }

    cout << cnt << endl;
    return 0;
}
