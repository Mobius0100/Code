#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int N = 1010;

int main()
{
    int apple[N],drop[N]={0};
    int m,n,max=0,index=-1,sum=0;

    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        cin >> apple[i];
        for(int j=0;j<m;j++)
        {
            int num;
            cin >> num;
            drop[i] += abs(num);
        }
        if(drop[i] > max)
        {
            max = drop[i];
            index = i;
        }

        apple[i] -= drop[i];
        sum += apple[i];
    }

    cout << sum << " " << index+1 << " " << drop[index] << endl;
    //printf("%d %d %d\n",sum,index,drop[index]);

    return 0;
}
