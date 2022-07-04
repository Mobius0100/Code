/*
    :Z字形扫描，给定二维数组，将其按Z字形输出
    ：东拼西补终于AC，感觉逻辑很乱，调试很久才补好，没有一个清晰的思路
    ：要确定好它的运动规律，以及边界；
    : 借鉴其他人的简洁思路，见201412-2_2.cpp
    
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 600;
int main()
{
    int n,cnt=0;
    int dir[8] = {0,1,1,-1,1,0,-1,1};
    int num[N][N] = {0};

    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> num[i][j];
        }
    }

    int i=0,j=0;
    while(cnt < n*n){
        for(int k=0;k<8;k+=2){
            if(i==n-1 && j == n-1){
                cout << num[i][j] << " ";
                cnt++;
                break;
            }
            if(k==0){
                cout << num[i][j] << " ";
                cnt++;
                if(j<n-1){                   
                    i += dir[k];
                    j += dir[k+1];
                }
                else {
                    i += dir[k+1];
                    j += dir[k];
                }
            }
            else if(k==2){
                while(j!=0 && i!=n-1){
                    cout << num[i][j] << " ";
                    cnt++;
                    i += dir[k];
                    j += dir[k+1];
                }
            }
            else if(k==6){
                while(i!=0 && j!=n-1){
                    cout << num[i][j] << " ";
                    cnt++;
                    i += dir[k];
                    j += dir[k+1];
                }
            }
            else {
                cout << num[i][j] << " ";
                cnt++;
                if(i<n-1){                   
                    i += dir[k];
                    j += dir[k+1];
                }
                else {
                    i += dir[k+1];
                    j += dir[k];
                }  
            }

            }
    }
    return 0;
}
