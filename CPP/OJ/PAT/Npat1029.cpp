/*
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int flag = 0;
    int cnt1=0,cnt2=0;

    string str1,str2;

    cin >> str1 >> str2;

    for(int i=0;i<str2.length();i++){
        int k = str1.find(str2[i]);

        if(k != -1) str1.erase(str1.begin() + k);
        else {
            cnt2++;
            flag = 1;
        }
    }

    if(flag){
        printf("No %d",cnt2);
    }else {
        printf("Yes %d",str1.length());
    }
    
    return 0;
}
