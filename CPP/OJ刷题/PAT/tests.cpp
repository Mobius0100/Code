/*
*/
#include <bits/stdc++.h>

using namespace std;

int B[5] = {1,2,3,4,5},temp[5];

int check(int A[]){
    for(int i=0;i<10;i++){
        if(A[i] != B[i]) return 0;
    }
    return 1;
}

int fun(int a[]){

    check(a);
}
int main()
{
    for(int i=0;i<5;i++){
        cin >> temp[i];
    }

    fun(temp);


     
    return 0;
}
