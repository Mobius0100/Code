/*
    贪心卖月饼，
    注意需求量要设为浮点数，后面要与浮点数相计算；
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 10010;

struct pie{
    double need,sale;
    double price;
}Pie[N];

bool cmp(pie a,pie b){
    return a.price > b.price;
}

int main()
{
    int n;
    double D,sum=0;
    cin >> n >> D;


    for(int i=0;i<n;i++){
        cin >> Pie[i].need;
    }

    for(int i=0;i<n;i++){
        cin >> Pie[i].sale;
        Pie[i].price = Pie[i].sale * 1.0 / Pie[i].need;
    }

    sort(Pie,Pie+n,cmp);

    for(int i=0;D>0&&i<n;i++){
        if(D >= Pie[i].need){
            D -= Pie[i].need;
            sum += Pie[i].sale;
        }
        else{
            sum += (D*Pie[i].price);
            D = 0;
        }
    }

    printf("%.2lf\n",sum);


    return 0;
}
