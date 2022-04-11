/*
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    char c;

    cin >> n >> c;

    int column = (n*1.0/2) + 0.5;
    for(int i=0;i<column;i++){
        for(int j=0;j<n;j++){
            if(i == 0 || j == 0 || i == column-1 || j == n-1) cout << c;
            else cout << ' ';
        }
        cout << endl;
    }

    return 0;
}
