/*
    
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<int,int > mp;
    int n,k,cnt=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> k;
        mp[k]++;
        if(mp[-k] > 0) cnt++;
    }

    cout << cnt << endl;
    return 0;
}
