/*
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;

bool isNum(int a, int b){
    int cnt = sqrt(abs(b));

    for(int i=-9999;i<10000;i++){
        if( i * (a-i) == b) return true;
    }

    return false;
}
int main()
{
    int n,m;

    while(cin >> n >> m){
        if(n==0 && m==0) break;

        if(isNum(n,m)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
