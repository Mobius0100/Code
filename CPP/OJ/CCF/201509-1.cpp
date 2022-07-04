/*
    :数列分段，给定一串数列，连续相同的为一段，问该数列有多少段
    ：单独一个也可以为一段
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 10000;

int main()
{
    int n,cnt=1,k1,k2;
    int num[N] = {0};
    cin >> n >> k1;

    for(int i=1;i<n;i++){
        cin >> k2;
        if(k2 != k1){
            cnt++;
        }
        k1 = k2;
    }

    cout << cnt << endl;
    return 0;
}
