/*
    
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 100000;

int main()
{
    long long n,num[N],max,min,k,imed;
    double fmed;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> num[i];
    }

    if(num[0] > num[n-1]){
        max = num[0];
        min = num[n-1];
    }
    else{
        max = num[n-1];
        min = num[0];
    }

    if(n%2 == 0){
        k = num[n/2 - 1] + num[n/2];
    }
    else k = num[n/2] * 2;

    if(k%2 == 0) printf("%lld %lld %lld",max,k/2,min);
    else printf("%lld %.1f %lld",max,k/2.0,min);

    return 0;
}
