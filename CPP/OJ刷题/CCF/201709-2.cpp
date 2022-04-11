/*
    :公共钥匙盒；N个钥匙一字排列，K个老师上下课时取还钥匙，问最终钥匙盒的排列顺序
    :用了结构体里加向量，感觉有点繁琐了；
    :将借和还的时间点都插入钥匙编号，用vector储存多个钥匙编号，并将还的钥匙进行从小到大排序
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX = 11000;

struct Time{
    vector<int> Borrow;
    vector<int> Re;
}t[MAX];
int main()
{
    int N,K,m=0;
    int key,t1,t2;
    int KeyBox[MAX] = {0};
    cin >> N >> K;
    for(int i=1;i<=N;i++) KeyBox[i] = i;
    for(int i=0;i<K;i++){
        cin >> key >> t1 >> t2;
        t[t1+1].Borrow.push_back(key);
        t[t2+t1+1].Re.push_back(key);
        if(t2+t1+1 > m) m = t2+t1+1;
    }

    for(int i=1;i<=m;i++){
        if(t[i].Re.size() != 0){
            sort(t[i].Re.begin(),t[i].Re.end());
            for(int j=0;j<t[i].Re.size();j++){
                for(int k=1;k<=N;k++){
                    if(KeyBox[k] == 0){
                        KeyBox[k] = t[i].Re[j];
                        break;
                    }
                }
            }
        }
        if(t[i].Borrow.size() != 0){
            for(int j=0;j<t[i].Borrow.size();j++){
                for(int k=1;k<=N;k++){
                    if(KeyBox[k] == t[i].Borrow[j]){
                        KeyBox[k] = 0;
                        break;
                    }
                }
            }
        }
    }

    for(int i=1;i<=N;i++){
        cout << KeyBox[i] << " ";
    }
    return 0;
}
