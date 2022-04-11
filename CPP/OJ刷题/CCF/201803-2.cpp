/*
    题意：碰撞的小球，指定小球个数和位置，赛道长度，预测t秒后小球的位置
    思路：用了结构体来标记是否相撞，感觉费时了，待优化。
        ：可以通过用两个循环来遍历小球，如果有相同的位置，则将小球反向（因为只存在两个小球发生碰撞）
*/
#include <bits/stdc++.h>

using namespace std;

struct flag{
    int index1;
    int index2;
};
int main()
{
    int n,L,t;
    int ball[110] = {0};
    int dir[110] = {0};

    cin >> n >> L >> t;

    for(int i=1;i<=n;i++){
        cin >> ball[i];
        dir[i] = 1;
    }
    for(int i=0;i<t;i++){
        flag f[1000];
        for(int j=1;j<=L;j++){
            f[j].index1 = 0;
            f[j].index2 = 0;
        }

        for(int j=1;j<=n;j++){
            ball[j] += dir[j];
            if(f[ball[j]].index1 != 0){
                f[ball[j]].index2 = j;
            }
            else f[ball[j]].index1 = j;

            if(ball[j] == L) dir[j] = - dir[j];
        }

        for(int j=1;j<=L;j++){
            if(f[j].index2 != 0){
                dir[f[j].index1] = -dir[f[j].index1];
                dir[f[j].index2] = -dir[f[j].index2];
            }
        }

    }

    for(int i=1;i<=n;i++){
        cout << ball[i];
        if(i != n) cout << " ";
    }
    return 0;
}
