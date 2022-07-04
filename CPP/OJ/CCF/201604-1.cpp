/*
    :折点；
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 10000;

int main()
{
    int n,cnt=0;
    int num[N] = {0};
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> num[i];
    }

    for(int i=1;i<n-1;i++){
        if(num[i-1] > num[i] && num[i+1] > num[i]) cnt++;
        else if(num[i-1] < num[i] && num[i+1] < num[i]) cnt++;
    }
    cout << cnt << endl;

    return 0;
}
