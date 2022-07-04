/*
int	4	-2147483648~2147483647
short int	2	-32768～+32767
long	4	-2147483648~2147483647（二十亿，约10^10)
long long	8	9223372036854775808～+9223372036854775807(九百亿亿，约10^19)
__int64	8	9223372036854775808～+9223372036854775807*/


#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
    map <int ,int> mp;
    int n,v1,a,b,v2;
    long long ans=0;

    cin >> n >> a >> b;

    for(int i=0;i<a;i++)
    {
        cin >> v1 >> v2;
        mp[v1] = v2;
    }

    for(int i=0;i<b;i++)
    {
        cin >> v1 >> v2;
        if(mp.count(v1) != 0) ans += mp[v1] * v2;    //判断map中key值是否存在！
    }

    cout << ans << endl;

    return 0;
}
