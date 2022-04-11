#include <bits/stdc++.h>
using namespace std;
#define Up(i,a,b) for(int i = a; i <= b; i++)
#define P pair<int,int>   //pair的first为整数,second为该整数出现的次数
 
bool cmp(P a,P b)
{
    if(a.second != b.second)    //若出现次数不一样多
    {
        return a.second > b.second;   //根据出现次数的多少来降序排列
    }
    else    //若出现次数一样多
    {
        return a.first < b.first;    //根据数字权值的大小来升序排列
    }
}
 
int main()
{
    int n;
    cin >> n;
    vector<P> v;
    map<int,int> m; 
    Up(i,1,n)
    {
        int _;
        cin >> _;
        m[_]++;
    }
    for(auto it : m)
    {
        v.push_back({it.first,it.second});
    }
    sort(v.begin(),v.end(),cmp);
    for(auto it : v)
    {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}