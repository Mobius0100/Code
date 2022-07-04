/*
    科学计数法转换；
    将输出字符作为基本循环（计算）单位，判断边界条件
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    int pos=1;

    cin >> str;
    if(str[0] == '-') cout << '-';

    while(str[pos] != 'E'){
        pos++;
    }

    int exp=0;
    for(int i = pos+2;i<str.length();i++){   //字符串转整数
        exp = exp * 10 + (str[i] - '0');
    }
    
    if(exp == 0){
        for(int i=1;i<pos;i++) cout << str[i];
    }

    if(str[pos+1] == '-'){
        cout << "0.";
        for(int i=0;i<exp-1;i++) cout << '0';
        cout << str[1];
        for(int i=3;i<pos;i++) cout << str[i];
    } else {
        for(int i=1;i<pos;i++){
            if(str[i] == '.') continue;
            cout << str[i];
            if(i == exp+2 && pos-3 !=exp){   //小数点加在exp+2的位置上，且该位置不能超过原有数字
                cout << '.';
            }
        }
        //指数较大，补全0
        for(int i=0;i<exp-(pos-3);i++) cout << '0';  
    }

    return 0;
}
