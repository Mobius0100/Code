/*
    题意：一圈小朋友报数，报到k的倍数或末位为k则淘汰，问最后一人是谁
          使用数组来标记答案超时，改用vector
          还可以使用队列来做，见201712-2_2.cpp

    // while(m != 1){
    //     for(int i=1;i<=n;i++){
    //         if(kid[i] != -1){
    //             if(num%k == 0 || num%10==k){
    //                 kid[i] = -1;
    //                 m--;
    //             }
    //             num++;
    //         }
    //     }
    // }
    // for(int i=1;i<=n;i++){
    //     if(kid[i] != -1) index = i;
    }
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,num=1;
    vector<int> kid;
    cin >> n >> k;

    for(int i=1;i<=n;i++) kid.push_back(i);
    for(vector<int>::iterator it = kid.begin();kid.size() != 1;){
        if(num%k == 0 || num%10==k){
            kid.erase(it);
        }
        else it++;
        if(it == kid.end()) it = kid.begin();
        num++;
    }

    cout << kid[0] << endl;

    return 0;
}
