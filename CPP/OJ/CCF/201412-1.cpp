/*
    
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num[1000] = {0};
    int n,k;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> k;
        num[k]++;
        printf("%d ",num[k]);
    }
    
    
    return 0;
}
