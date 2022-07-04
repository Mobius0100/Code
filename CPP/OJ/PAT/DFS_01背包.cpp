/*
    
*/
#include <bits/stdc++.h>

using namespace std;
const int N = 100010;

int w[N],c[N],V,n;    //n件物品，V容量背包
int maxV = 0;
void DFS(int index,int sumW, int sumV){
    if(index == n){
        if(sumW <= V && sumV > maxV) maxV = sumV;
        return;
    }

    DFS(index+1,sumW,sumV);
    DFS(index+1,sumW+w[index],sumV+c[index]);
    
}

//剪枝优化版
void DFS2(int index,int sumW, int sumV){
    if(index == n) return;

    DFS2(index+1,sumW,sumV);
    if(sumW + w[index] <= V){
        if(sumV + c[index] > maxV) maxV = sumV + c[index];
        DFS2(index+1,sumW+w[index],sumV+c[index]);
    }
}

int main()
{
    cin >> n >> V;
    for(int i=0;i<n;i++) cin >> w[i];
    for(int i=0;i<n;i++) cin >> c[i];
    DFS2(0,0,0);

    cout << maxV << endl;

    return 0;
}
