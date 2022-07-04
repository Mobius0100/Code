/*
    题意：找出所给字符串的公共后缀，如果没有则输出nai
*/
#include <bits/stdc++.h>

using namespace std;

string str[110];
int main()
{
    int n,min=256,index = -1;
    cin >> n;
    getchar();
    
    for(int i=0;i<n;i++){
        getline(cin,str[i]);
        if(str[i].length() < min) min = str[i].length();
    }

    for(int i=0;i<n;i++){
        int len = str[i].length();
        char c;
        for(int j=0;j<len/2;j++){
            c = str[i][j];
            str[i][j] = str[i][len-1-j];
            str[i][len-1-j] = c;
        }
    }
    bool flag = false;
    for(int i=0;i<min;i++){
        char c = str[0][i];
        flag = false;
        for(int j=0;j<n;j++){
            if(c != str[j][i]){
                flag = true;
                break;
            }
        }

        if(flag == true){
            index = i;
            break;
        }
    }

    if(index == 1) printf("nai\n");
    else for(int i=index-1;i>=0;i--) cout << str[0][i] ;

    return 0;
}
