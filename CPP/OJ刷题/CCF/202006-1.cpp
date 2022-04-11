#include <iostream>
#include <cstdio>
#include <map>

using namespace std;
const int N = 1000+10;

struct Point{
    int x;
    int y;
    char type;
}point[N];

int main()
{
    int n,m;
    cin >> n >> m;

    int a,b,c;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %c",&point[i].x,&point[i].y,&point[i].type);
    }

    for(int i=0;i<m;i++)
    {
        cin >> a >> b >> c; 
       int n1=0,n2=0;
        for(int j=0;j<n;j++)
        {
            int value = a + point[j].x * b + point[j].y * c;
            if(point[j].type == 'A')
            {
                if(value > 0) n1 = 1;
                else n1 = -1;
            }

            if(point[j].type == 'B')
            {
                if(value > 0) n2 = 1;
                else n2 = -1;
            }

            if(n1 == n2) break;
        }

        if(n1 == n2) cout << "No" << endl;
        else cout << "Yes" <<endl;

    }
    return 0;
}
