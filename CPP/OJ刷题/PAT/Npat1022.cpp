/*
*/
#include <bits/stdc++.h>

using namespace std;

const int Maxn = 100010;

struct Person{
    int schNum;
    int score;
}person[Maxn];

int main()
{
    int sum[Maxn] = {0};
    int n,num,score,index,m=-1;
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> num >> score;
        sum[num] += score;
        if(sum[num] > m){
            index = num;
            m = sum[num];
        }
    }

    cout << index << " " << m;

    return 0;
}
