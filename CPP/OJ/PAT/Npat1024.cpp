/*
*/
#include <bits/stdc++.h>

using namespace std;

struct Num{
    int k;
    int a,b;
    char flag;
}num[3];

char C[4] = {'+','-','*','/'};

int main()
{
    scanf("%d/%d %d/%d",&num[0].a,&num[0].b,&num[1].a,&num[1].b);
    for(int i=0;i<2;i++){
        if(num[i].a < 0) num[i].flag = '-';
        num[i].k = abs(num[i].a / num[i].b);
        if(num[i].k != 0) num[i].a = abs(num[i].a % num[i].b);
    }

    for(int i=0;i<4;i++){
        if(num[0].flag == '-') cout << "(-";
        if(num[0].k != 0) cout << num[0].k << " ";
        if(num[0].a != 0){
            printf("%d/%d",num[0].a,num[0].b);
        }
        if(num[0].flag == '-') cout << ")";

        printf(" %c ",C[i]);

        if(num[1].flag == '-') cout << "(-";
        if(num[1].k != 0) cout << num[1].k << " ";
        if(num[1].a != 0){
            printf("%d/%d",num[1].a,num[1].b);
        }
        if(num[1].flag == '-') cout << ")";

        printf(" = ");

        switch (i)
        {
            case 0:{
                num[2].k = num[0].k + num[1].k;
            } break;
            case 1:
            case 2:
            case 3:
        }
        
    }

    return 0;
}
