#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main()
{
    string s = "leetcode";
    map<char, int> mp;
    for(int i=0; i<s.length(); i++){
        mp[s[i]]++;
    }

    for(auto it = mp.begin(); it != mp.end(); it++){
        cout << it->first << ":" << it->second << endl;
    }
    
    return 0;
}