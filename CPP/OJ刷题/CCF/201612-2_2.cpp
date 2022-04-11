#include <iostream>
#define inf 0x3f3f3f3f
 
using namespace std;
int baseA[8] = {0,0,1500,4500,9000,35000,55000,80000};
double rate[8] = {0,97,90,80,75,70,65,55};
int rang[8];
void init()
{
    //2
    rang[0] = 0;
    rang[1] = 1500*97/100;
    rang[2] = rang[1]+3000*0.9;
    rang[3] = rang[2]+4500*0.8;
    rang[4] = rang[3]+(35000-9000)*0.75;
    rang[5] = rang[4]+(55000-35000)*0.7;
    rang[6] = rang[5]+(80000-55000)*0.65;
    rang[7] = inf;
}
 
 
int main()
{
    int M;
    int T;
    cin>>M;
    init();
    if(M<3500)
        T = M;
 
    else
    {
        int state = 1;
        for(int i =1;i<=6;i++)
        {
            if(M>rang[i]+3500)
            {
                state = i+1;
            }
 
        }
       // cout<<M-rang[state-1]-3500<<endl;
        T = baseA[state]+3500+(M-rang[state-1]-3500)/rate[state]*100;
 
    }cout<<T;
    return 0;
}