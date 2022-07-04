/*
*/
#include <bits/stdc++.h>

using namespace std;

int num[4] = {0};
int N;

void numToStr(int n){
    int k=1000;
    for(int i=0;i<4;i++){
        num[i] = n/k;
        n = n%k;
        k = k/10;
    }
}

int strToNum(){
    int k=1000;
    int n = 0;
    for(int i=0;i<4;i++){
        n += num[i]*k;
        k = k/10;
    }
    return n;
}

bool cmp(int a,int b){
    return a > b;
}

int main()
{
    cin >> N;
    numToStr(N);

    if(num[0]==num[1] && num[1] == num[2] && num[2] == num[3]){
        printf("%04d - %04d = 0000\n",N,N);
    }
    else{
        int n1,n2;
        do{
            sort(num,num+4,cmp);
            n1 = strToNum();
            sort(num,num+4);
            n2 = strToNum();
            N = n1-n2;
            numToStr(N);
            printf("%04d - %04d = %04d\n",n1,n2,N);
        }while(N!=6174);
    }


    return 0;
}
