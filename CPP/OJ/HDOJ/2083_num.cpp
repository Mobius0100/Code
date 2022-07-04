/*
    打表解决超时问题
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;

const int maxn = 1000000;
int num[maxn+10] = {0};

void hashTable(){
    string s = "";
    for(int i=0; i<maxn; i++){
        s = to_string(i);
        if(s.find("4") != -1 || s.find("62") != -1){
            num[i]++;
        }
    }
}

int main()
{
    int n,m;

    hashTable();
    while(cin >> n >> m){
        if(n == 0 && m == 0) break;

        int ans = 0;
        for(int i=n; i<=m; i++){
            ans += num[i];
        }

        cout << m - n - ans + 1<< endl;
    }

    return 0;
}
