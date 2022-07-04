/*
    
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 100000;
int main()
{
    int n,a[N]={0},b[N];
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];

    b[1] = (a[1]+a[2])/2;
    b[n] = (a[n]+a[n-1])/2;
    for(int i=2;i<n;i++){
        b[i] = (a[i-1] + a[i] + a[i+1])/3;
    }

    for(int i=1;i<=n;i++){
        cout << b[i];
        if(i != n) cout << " ";
    }

    return 0;
}
