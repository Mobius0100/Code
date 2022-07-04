/*
    :中间数，一组数列中，大于一个数的个数=小于该数的个数，称为中间数
    ：给定数列，输出其中间数，没有则输出-1
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 10000;
int main()
{
    int n;
    int a[N] = {0};
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    sort(a,a+n);

    int i,j;
    for(i=n/2;a[i] == a[n/2];i--);
    for(j=n/2;a[j] == a[n/2];j++);

    if(i+1 == n-j) cout << a[n/2];
    else cout << -1;

    return 0;
}
