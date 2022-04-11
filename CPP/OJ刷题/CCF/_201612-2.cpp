/*
    ：工资计算；
    ：给定税后T，计算税前S；
    : 可暴力求解，从3500开始，100递增，求出对应的税后工资与T是否相等
    ：应用方法见201612-2_2.cpp
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;

    int s[8] = {3500,1455,2700,3600,19500,14000,16250,11000};
    double rate[8] = {0,0.97,0.9,0.8,0.75,0.7,0.65,0.55};
    int t[8]= {0,3500,5000,8000,12500,38500,58500,83500};

    int k=0,i;
    for(i=0;i<8;i++){
        if(k+s[i] < T) k += s[i];
        else break;
    }

    int ans = t[i] + (T-k) / rate[i];

    cout << ans << endl;
    return 0;
}
