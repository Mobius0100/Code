#include <iostream>
using namespace std;
int main()
{
    int n,tot = 0;
    cin>>n;
    int num[n + 1][n + 1];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin>>num[i][j];
    int a = 1,b = 1,c = 1;
    //c为状态：1向右,2左下,3向下,4右上
    while(a + b <= 2 * n - 1)
    {
        switch(c)
        {
        case 1:
            cout<<num[a][b++]<<" ";
            if(a == 1)
                c = 2;
            if(a == n)
                c = 4;
            break;
        case 2:
            cout<<num[a++][b--]<<" ";
            if(b == 1)
                c = 3;
            if(a == n)
                c = 1;
            break;
        case 3:
            cout<<num[a++][b]<<" ";
            if(b == 1)
                c = 4;
            else
                c = 2;
            break;
        case 4:
            cout<<num[a--][b++]<<" ";
            if(a == 1 && b != n)
                c = 1;
            else if(b == n)
                c = 3;
            break;
        }
    }
    cout<<num[a][b];
    return 0;
}