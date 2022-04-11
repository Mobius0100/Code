/*
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;
const int maxn = 10010;

int num[maxn] = {0};   //素数列表
int isp[maxn] = {0};   //素数hash表

// 是否是素数
bool isPri(int m){
    for(int i=2;i<=sqrt(m);i++){
        if( m % i == 0) return false;
    }
    return true;
}

int main()
{
    int index = 0;
    for(int i=2;i<maxn;i++){
        if(isPri(i)){
            if(isp[i] = 1);
            num[index++] = i;
        }
    }   

    int n;
    while(cin >> n){
        if(n == 0) break;

        int cnt = 0;
        for(int i=0;num[i]< n/2;i++){
            if(isp[n - num[i]] == 1) cnt++;
        }
        cout << cnt << endl;
    }

    return 0;
}
