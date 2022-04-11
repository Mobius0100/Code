/*
    打酱油，买3送1，买5送2；问能买多少
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int money,cnt=0;
    cin >> money;

    cnt = money / 10;
    if(money >= 50){
        cnt += (money / 50) * 2;
        money = money % 50;
    }
    if(money >= 30){
        cnt += money / 30;
    }

    cout << cnt << endl;
    return 0;
}
