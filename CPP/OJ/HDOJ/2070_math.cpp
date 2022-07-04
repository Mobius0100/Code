/*
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

ll fibnum[60] = {0};

ll fibbonacci(int k){
    if(k==0 || k==1) return k;
    else{
        return fibbonacci(k-1) + fibbonacci(k-2);
    }
}

ll fib(int k){
    fibnum[0] = 0;
    fibnum[1] = 1;

    for(int i=2;i<=k;i++){
        fibnum[i] = fibnum[i-1] + fibnum[i-2];
    }

    return fibnum[k];
}
int main()
{
    int n;
    while(cin >> n){
        if(n == -1) break;
        cout << fib(n) << endl;
    }

    return 0;
}
