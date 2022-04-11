/*
*/
#include <bits/stdc++.h>

using namespace std;

struct money{
    int G,S,K;
};

int main()
{
    money P,A,ans;

    scanf("%d.%d.%d %d.%d.%d",&P.G,&P.S,&P.K,&A.G,&A.S,&A.K);

    ans.K = A.K - P.K;
    ans.S = A.S - P.S;
    ans.G = A.G - P.G;

    if(ans.K < 0){
        ans.S--;
        ans.K += 29;
    }

    if(ans.S < 0){
        ans.G--;
        ans.S += 17;
    }

    if(ans.G < 0){
        ans.K = P.K - A.K;
        ans.S = P.S - A.S;
        ans.G = P.G - A.G;
        
        if(ans.K < 0){
            ans.S--;
            ans.K += 29;
        }

        if(ans.S < 0){
            ans.G--;
            ans.S += 17;
        }
        printf("-");
    }
    printf("%d.%d.%d",ans.G,ans.S,ans.K);




    return 0;
}
