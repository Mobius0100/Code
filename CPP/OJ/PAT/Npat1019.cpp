/*
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str1,str2;
    map<char,int> mp;
    cin >> str1 >> str2;

    int len = str1.length();
    for(int i=0;i<len;i++){
        if(str2.find(str1[i]) == string::npos){
            if(str1[i] >= 'a' && str1[i] <= 'z') str1[i] += ('A'-'a');
            if(mp.count(str1[i]) == 0 ){
                mp[str1[i]] = 1;
                cout << str1[i];
            }
        }
    }
    return 0;
}
