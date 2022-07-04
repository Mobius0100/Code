/*
    
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1000;

int w[N],c[N];
int dp[N][N];
int main()
{
    int n,V;
    cin >> n >> V;
    for(int i=1;i<=n;i++) cin >> w[i];
    for(int i=1;i<=n;i++) cin >> c[i];

    for(int v=0;v<=V;v++) dp[0][v] = 0;
    for(int i=1;i<=n;i++){
        for(int v=w[i];v<=V;v++){
            dp[i][v] = max(dp[i-1][v],dp[i-1][v-w[i]] + c[i]);
        }
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=V;j++) cout << dp[i][j] << " ";
        cout << endl;
    }
    return 0;
}
