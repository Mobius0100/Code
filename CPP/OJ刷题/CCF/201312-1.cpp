/*
    
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<int ,int> mp;
    int n,k,max=-1,max_i = -1;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> k;
        mp[k]++;
    }

    for(map<int,int>::iterator it = mp.begin();it != mp.end();it++){
        if(it->second > max){
            max = it->second;
            max_i = it->first;
        }
    }

    cout << max_i << endl;
    return 0;
}
