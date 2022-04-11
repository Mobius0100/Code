/*
    toupper(int c)
    tolower(int c)   //ctype.h
    isalnum()
    isdigit()
    isupper()
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str1,str2,str3;
    cin >> str1 >> str2;
    int flag = 0;

    if(str1.find('+') != string::npos) flag = 1;
    for(string::iterator it = str2.begin(); it != str2.end(); it++){
        if(flag && isupper(*it)) continue;
        else if(str1.find(toupper(*it)) != string::npos) continue;
        else cout << *it;
    }

    return 0;
}
