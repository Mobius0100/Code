/*
    :ISBN号码；给定ISBN号码，检测其最后一位识别码是否正确，正确则输出Right，否则输出正确号码
    识别码计算：前9个数字，依次乘1，2，3....8,9;所得之和对11取余
    若mod==10，则识别码为X
*/
#include <bits/stdc++.h>
#include <string>

using namespace std;

int main()
{
    string str;
    int sum = 0;
    cin >> str;

    int len = str.length() - 1;
    int j=1;
    for(int i=0;i<len-1;i++){
        int k = str[i] - '0';
        if(k >= 0 && k <= 9){
            sum += (k*j);
            j++;
        }
    }

    int mod = sum % 11;

    if(mod == 10 ){
        if(str[len] == 'X') cout << "Right" << endl;
        else{
            str[len] = 'X';
            cout << str << endl;
        }
    }
    else if(mod == (str[len] - '0')){
        cout << "Right" << endl;
    }
    else{
        str[len] = mod + '0';
        cout << str << endl;
    }

    return 0;
}
