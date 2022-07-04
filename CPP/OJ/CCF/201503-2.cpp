/*
    :数字排序；将出现的数字次数统计起来，并按出现次数递减序列输出
    ：用的结构体记录数字和数字出现次数，然后再排序
    ：使用map来记录数据，用vector<pair<int ,int>> v来存结果，见201503-2_2.cpp
    
*/
#include <bits/stdc++.h>

using namespace std;

struct number{
    int n;
    int cnt;
}num[1100];

bool cmp(number a,number b){
    if(a.cnt != b.cnt) return a.cnt > b.cnt;
    else return a.n < b.n;
}

int main()
{
    int n,k;
    cin >> n;
    for(int i=0;i<1100;i++){
        num[i].cnt = 0;
        num[i].n = 1000;
    }
    for(int i=0;i<n;i++){
        cin >> k;
        num[k].n = k;
        num[k].cnt++;
    }

    sort(num,num+1100,cmp);

    for(int i=0;num[i].cnt > 0;i++){
        cout << num[i].n << " " << num[i].cnt << endl;
    }
    return 0;
}
