/*
    c++接受含空格的字符串：
        getline(cin,str);
    
    按空格来分割字符串时，以一个单词为循环
    记得清空容器
*/
#include <string>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    string str,tmp;
    map<string, int> mp;

    while(getline(cin,str)){
        if(str == "#") break;

        mp.clear();  
        
        int len=str.length();
        for(int i = 0;i < len; i++){
            if(str[i] != ' '){
                int j;
                tmp.clear();
                
                //添加一个单词
                for(j=i; j < len && str[j] != ' '; j++){
                    tmp += str[j];
                }
                i = j;
                mp[tmp]++;   //也可使用set.insert(tmp)
            }   
        }
        
        cout << mp.size() << endl;
    }

    return 0;
}
