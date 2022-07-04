/*
    :找出所给数列中两两差值最小的插值（绝对值）
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 10000;
int main()
{
    int n,a[N];
    int ans=10000;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);

    for(int i=1;i<n;i++){
        if(a[i] - a[i-1] < ans) ans = a[i] - a[i-1];
    }

    cout << ans << endl;

    return 0;
}
