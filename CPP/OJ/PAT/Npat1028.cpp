/*
*/
#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;

int main()
{
    int map[maxn] = {0};
    int n,score;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> score;
        map[score]++;
    }

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> score;
        cout << map[score];
        if(i < n-1) cout << " ";
    }
    
    return 0;
}
