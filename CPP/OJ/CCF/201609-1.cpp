/*
    :计算最大波动
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,ans=-1,k1,k2;
    cin >> n >> k1;
    for(int i=1;i<n;i++){
        cin >> k2;
        if(abs(k2-k1) > ans) ans = abs(k2-k1);
        k1 = k2;
    }

    cout << ans << endl;
    return 0;
}
