/*
    :买菜；两人去广场装菜，给定时间段，问两人都在广场的时间
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1000000;
int a[N] = {0};

int main()
{
    int n;
    long long s,t,cnt=0;

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> s >> t;
        for(int j=s;j<t;j++) a[j] = 1;
    }

    for(int i=0;i<n;i++){
        cin >> s >> t;
        for(int j=s;j<t;j++){
            if(a[j] == 1) cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
