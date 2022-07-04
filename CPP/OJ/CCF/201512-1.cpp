/*
    :数位之和
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    cin >> str;
    
    int ans=0;
    int len = str.length();
    for(int i=0;i<len;i++){
        ans += (str[i] - '0');
    }

    cout << ans << endl;
    return 0;
}
