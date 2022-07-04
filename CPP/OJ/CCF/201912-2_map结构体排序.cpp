#include <iostream>
#include <map>


using namespace std;

struct point{
    long long x;
    long long y;
    bool operator<(const point& A)const{       //map内部为红黑树，对数据自动排序，当键是结构体时，其无小于号操作故无法进行排序操作，所以要对结构体<号重载
        if(this->x < A.x) return true;
        else if(this->x == A.x && this->y < A.y) return true;
        else return false;
    }
}p;

map<point, int> mp;

int check(long long x, long long y)
{
    point p;
    p.x = x;
    p.y = y;
    if(mp.count(p) == 0) return 0;
    else return 1;
}

int main()
{

    int n,ans[5]={0};

    cin >> n;

    for(int i=0;i<n;i++)
    {
        cin >> p.x >> p.y;
        mp[p]++;
    }

    for(map<point,int >::iterator it = mp.begin(); it != mp.end(); it++)
    {
        int score=0;
        p = it->first;
        if(check(p.x + 1, p.y) && check(p.x, p.y + 1) && check(p.x - 1, p.y) && check(p.x, p.y - 1)) 
        {
            if(check(p.x + 1, p.y + 1)) score++;
            if(check(p.x - 1, p.y + 1)) score++;
            if(check(p.x - 1, p.y - 1)) score++;
            if(check(p.x + 1, p.y - 1)) score++;

            ans[score]++;
        }

    }

    for(int i=0;i<5;i++)
        cout << ans[i] << endl;
    return 0;
}
