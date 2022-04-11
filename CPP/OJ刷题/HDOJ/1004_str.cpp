/*
*/
#include <cstdio>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int n;
    map<string, int> mp;
    while(scanf("%d",&n) != 0){
        
        mp.clear();
        string str,ans;
        int cnt=-1;

        for(int i=0;i<n;i++){
            cin >> str;
            mp[str]++;
            if(mp[str] > cnt){
                cnt = mp[str];
                ans = str;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
