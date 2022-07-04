/*
    :期末安全阈值；给定重要程度w,和分数score；求MAX(SUM = WI*SCOREI,0);
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,sum=0,w,score;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> w >> score;
        sum += (w*score);
    }

    cout << max(0,sum) << endl;
    return 0;
}
