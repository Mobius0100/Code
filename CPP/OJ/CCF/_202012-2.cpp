/*
    :期末最佳阈值；根据所给的历史阈值和挂科情况，求出最佳阈值
    ：  最佳阈值仅在yi中选取，即与某位同学的安全指数相同；
        按照该阈值对这m位同学上学期的挂科情况进行预测，预测正确的次数最多（即准确率最高）；
        多个阈值均可以达到最高准确率时，选取其中最大的。
    :一开始使用map记录每个阈值的正确次数，但时间复杂度高，运行超时；看别人使用前缀后缀和来加速
    思路：1.将输入的阈值和结果按阈值升序
          2.计算0的前缀和，1的后缀和
          3.将重复的阈值下标置为第一次出现的位置
          4.遍历可得该位置的前缀和+后缀和即为答案
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
struct Data{
    long long y;
    int result;
}dat[N];

int pres[N] = {0},hpres[N] = {0},p[N] = {0};

bool cmp(Data a,Data b){
    return a.y < b.y;
}

int main()
{   
    int m;
    cin >> m;
    for(int i=1;i<=m;i++){
        cin >> dat[i].y >> dat[i].result;
    }

    sort(dat+1, dat+m+1,cmp);

    for(int i=1;i<=m;i++){
        pres[i] = pres[i-1] + (dat[i].result == 0 ? 1:0);
    }

    for(int i=m;i>=1;i--){
        hpres[i] = hpres[i+1] + (dat[i].result == 1 ? 1:0);
    }
    int max=-1,max_i=-1;
    

    int pos = 1;
    p[1] = 1;
    for(int i = 1; i <= m; i++)
        if(dat[i].y == dat[i - 1].y)
            p[i] = pos;
        else
            p[i] = (pos = i);

    for(int i=1;i<=m;i++){
        int cur = pres[p[i]-1] + hpres[i];
        if(cur >= max){
            max = cur;
            max_i = dat[i].y;
        }
    }
    // for(map<long long,int>::iterator it = mp.begin();it != mp.end(); it++){
    //     int thta = it->first,cnt=0;
    //     for(int i=0;i<m;i++){
    //         int pred = 1;
    //         if(dat[i].y < thta) pred = 0;
    //         if(pred == dat[i].result) cnt++;
    //     }
    //     it->second = cnt;

    //     if(it->second >= max){
    //         max = it->second;
    //         max_i = it->first;
    //     }

    // }

    cout << max_i << endl;
    return 0;
}
