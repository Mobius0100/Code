/*
*/
#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;
const int MOD = 1000000007;

int main()
{
    string str;
    int P[maxn]= {0},T[maxn] = {0};
    int sum =0;

    cin >> str;
    int len = str.length();

    for(int i=1;i<=len;i++){
        if(str[i-1] == 'P'){
            P[i] = P[i-1] + 1;
        }
        else P[i] = P[i-1];
    }

    int t=0;
    for(int i=len-1;i>=0;i--){
        if(str[i] == 'T'){
            t++;
        } else if(str[i] == 'A'){
            sum = (sum + P[i+1] * t) % MOD;
        }
    }

    cout << sum << endl;

    return 0;
}
