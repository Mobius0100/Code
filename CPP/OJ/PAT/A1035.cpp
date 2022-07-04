/*
    题意：输入账号密码，将密码中的10lO转换为@%Lo，并输出修改的账号与密码
    
*/

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

const int N = 1010;

struct student{
    string name;
    string passwd;
    int mod;
}stu[N];

int main()
{
    int n,cnt=0;
    cin >> n;

    for(int i=0;i<n;i++) stu[i].mod = 0;
    for(int i=0;i<n;i++){
        cin >> stu[i].name >> stu[i].passwd;

        string str = stu[i].passwd;
        int len = str.length();
        for(int j=0;j<len;j++){
            if(str[j] ==  '1' || str[j] =='0' || str[j] == 'l' || str[j] == 'O'){
                stu[i].mod = 1;
                if(str[j] == '1') stu[i].passwd[j] = '@';
                if(str[j] == '0') stu[i].passwd[j] = '%';
                if(str[j] == 'l') stu[i].passwd[j] = 'L';
                if(str[j] == 'O') stu[i].passwd[j] = 'o';
            }
        }
        if(stu[i].mod == 1) cnt++;
    }

    
    if(cnt == 0){
        if(n==1) cout << "There is 1 account and no account is modified" << endl;
        else cout << "There are " << n << " accounts and no account is modified" << endl;
    }
    else{
        cout << cnt << endl;
        for(int i=0;i<n;i++){
        if(stu[i].mod == 1){
            cout << stu[i].name << " " << stu[i].passwd << endl;
        }
        }

    }


    return 0;
}
