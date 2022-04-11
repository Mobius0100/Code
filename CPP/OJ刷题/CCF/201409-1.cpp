/*
    :问数列中相差为1的一组数有多少
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,cnt=0;
    cin >> n;
    int num[n];

    for(int i=0;i<n;i++){
        cin >> num[i];
    }

    sort(num,num+n);

    for(int i=1;i<n;i++){
        if(num[i] - num[i-1] == 1) cnt++;
    }

    cout << cnt << endl;
    return 0;
}
