/*
    :快速排序确定主元；给定一个排列，问有多少个元素可能是主元
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 10010;
const int INF = 0x3fffff;

int main()
{
    int n,num[N]={0},lmax[N]={0},rsmall[N] = {0},ans[N] = {0};
    cin >> n;
    
    for(int i=0;i<n;i++) cin >> num[i];
    lmax[0] = 0;
    for(int i=1;i<n;i++){
        lmax[i] = max(lmax[i-1], num[i-1]);
    }

    rsmall[n-1] = INF;
    for(int i=n-2;i>=0;i--){
        rsmall[i] = min(rsmall[i+1], num[i+1]);
    }

    int index = 0;
    for(int i=0;i<n;i++)
    {
        if((lmax[i] < num[i]) && (rsmall[i] > num[i])){
            ans[index++] = num[i];
        }
    }    

    cout << index << endl;

    for(int i=0;i<index;i++){
        cout << ans[i];
        if(i < index - 1) cout << " ";
    }


    return 0;
}
