#include <iostream>

using namespace std;

int main()
{
    int n,k,t,Num[20]={0},all[20]={0};
    int xl,xr,yl,yr;

    cin >> n >> k >> t >> xl >> yl >> xr >> yr;
	
    for(int i=0,x,y;i<n;i++)
    {
        int flag = 0;
        for(int j=0;j<t;j++)
        {
            cin >> x >> y;
 
            if(x >= xl && x <= xr && y >= yl && y <= yr)
            {
                Num[i]++;
                flag++;
                if(flag >= k) all[i]++;
            }
            else flag = 0;
        }
    }

    int ans1=0,ans2=0;
    for(int i=0;i<n;i++)
    {
        if(Num[i] > 0 ) ans1++;
        if(all[i] > 0 ) ans2++;
    }

    cout << ans1 << endl << ans2;
    
    return 0;
}
