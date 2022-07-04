/*
    题意：跳一跳，遇1加1，遇2加2，如有连续2，每次比上次多加2，0结束
          输出总分
*/
#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main()
{
    int cnt=1,ans=0,num;

    cin >> num;
    while(num != 0){
        if(num == 1){
            ans += num;
            cnt = 1;
        }
        if(num == 2){
            ans += (cnt * num);
            cnt++;
        }
        cin >> num;
    }

    cout << ans << endl;
    return 0;
}
