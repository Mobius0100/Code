/*
    :统计小明上学的时间
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,r,y,g;
    int type,time,ans=0;

    cin >> r >> y >> g >> n;

    for(int i=0;i<n;i++){
        cin >> type >> time;
        if(type == 0) ans+=time;
        else if(type == 1) ans += time;
        else if(type == 2) ans += time + r;
    }

    cout << ans << endl;
    return 0;
}
