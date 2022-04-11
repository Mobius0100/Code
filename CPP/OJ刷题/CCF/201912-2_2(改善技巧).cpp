/*
    使用pair来代替结构体，不需要重载结构体<号；
    使用auto来自动识别迭代器，简写代码
    使用typedef 来修改默认变量类型
*/

#include <iostream>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

pll pr;
map<pll, int> mp;

int check(ll x, ll y)
{
    pll p(x,y);
    if(mp.count(p) == 0) return 0;
    else return 1;
}

int main()
{

    int n,ans[5]={0};

    cin >> n;

    for(int i=0;i<n;i++)
    {
        cin >> pr.first >> pr.second;
        mp[pr]++;
    }

    //for(map<pair<ll, ll>,int >::iterator it = mp.begin(); it != mp.end(); it++)
    //for(auto it = mp.begin();it != mp.end(); it++);
    for(auto &it:mp)
    {
        int score=0;
        pll p = it.first;
        if(check(p.first + 1, p.second) && check(p.first, p.second + 1) && check(p.first - 1, p.second) && check(p.first, p.second - 1)) 
        {
            if(check(p.first + 1, p.second + 1)) score++;
            if(check(p.first - 1, p.second + 1)) score++;
            if(check(p.first - 1, p.second - 1)) score++;
            if(check(p.first + 1, p.second - 1)) score++;

            ans[score]++;
        }

    }

    for(int i=0;i<5;i++)
        cout << ans[i] << endl;
    return 0;
}
