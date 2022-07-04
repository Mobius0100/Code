/*
    题意：分蛋糕，每次分最小一块，直到大于等于k，开始分给下一个人，问多少人分到蛋糕

*/
#include <bits/stdc++.h>

using namespace std;

const int M = 100000;
int main()
{
    int n,k,w=0,cnt=0;
    int weight[M];
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> weight[i];
    }

    for(int i=0;i<n;i++){
        w += weight[i];
        if(w >= k){
            cnt++;
            w = 0;
        }
    }
    if(w != 0) cnt++;
    
    cout << cnt << endl;
    return 0;
}
