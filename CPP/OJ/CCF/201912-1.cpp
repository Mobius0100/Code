#include <iostream>
#include <cstdio>

using namespace std;

int check7(int a)
{
    if(a>=100)
    {
        if(a/100 == 7) return 1;
        if(a%100/10 == 7) return 1;
        if(a%100%10 == 7) return 1;
        return 0;
    }
    else 
    {
        if(a/10 == 7) return 1;
        if(a%10 == 7) return 1;
        return 0;
    }
}

int main()
{
    int n;
    int student[5]={0};
    int cnt=0;

    cin >> n;

    for(int i=1;cnt < n;i++)
    {
        if(i%7==0 || check7(i))
        {
            if(i%4 == 0) student[4]++;
            else student[i%4]++;
            continue;
        }

        cnt++;
    }

    for(int i=1;i<=4;i++) cout << student[i] << endl;


    return 0;
}
