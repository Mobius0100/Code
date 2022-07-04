/*
    c++接受含空格的字符串：
        getline(cin,str);
*/
#include <string>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    string str;
    map<string, int> mp;

    while(getline(cin,str)){
        if(str == "#") break;

        mp.clear();  
        string tmp;
        
        int i = 0, j = 0, len=str.length();

        for(i = 0;i<len;i++){
            if(str[i] != ' '){
                int j;
                tmp.clear();

                for(j=i; j < len && str[j] != ' '; j++){
                    tmp += str[j];
                }
                i = j;
                mp[tmp]++;
            }   
        }
        cout << mp.size() << endl;
    }
    return 0;
}
