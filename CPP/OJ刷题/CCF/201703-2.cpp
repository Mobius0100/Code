/*
    ：学生排队；1-n个学号的学生，每次指定学号对其进行队列调整，问最终的学号排列
    ：熟用vector的erase和insert方法，可以较快得到答案
    ：所有方法以0开始为坐标
    ：v.erase(it);v.erase(begin,end);
    : v.insert(it,x);
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    vector<int> v;

    cin >> n >> m;
    for(int i=0;i<=n;i++){
        v.push_back(i);
    }

    for(int i=0;i<m;i++){
        int num,dist,d;
        cin >> num >> dist;
        for(int j=1;j<=n;j++){
            if(v[j] == num){
                d = j + dist;
                v.erase(v.begin() + j);
                break;
            }
        }
        v.insert(v.begin() + d,num);
    }

    for(int i=1;i<=n;i++){
        cout << v[i] << " ";
    }
    return 0;
}
