/*
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 100010;

int main()
{
    int N,ans=-1;
    ll num[maxn],p;

    cin >> N >> p;
    for(int i=0;i<N;i++){
        cin >> num[i];
    }

    sort(num,num+N);
    int i=0,j=0;
    // for(i=0;i<N;i++){
    //     for(j=0;j<N;j++){
    //         if(num[j] <= num[i]*p){
    //             ans = max(ans,j-i+1);
    //             break;
    //         }
    //     }
        
    // }

    while(i<N && j<N){
        while(j<N && num[j] <= num[i]*p){
            ans = max(ans,j-i+1);
            j++;
        }
        i++;
    }

    cout << ans;
    return 0;
}
