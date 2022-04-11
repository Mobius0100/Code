/*
    :火车购票;5x20个座位，给定买票数，如有连续的座位，先安排连续座位，否则按座位编号从小到大安排
    ：使用vector数组来判断是否有连续座位，有则输出后删除
    ：可以使用queue来代替vector；
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,cmd;
    vector<vector<int> > vi;
    vector<int> v[20];

    cin >> n;

    for(int i=1,j=0;i<=100;i++){    //按1-100分配座位，隔5换下一排
        v[j].push_back(i);
        if(i%5 == 0) j++;
    }

    for(int i=0;i<n;i++){
        cin >> cmd;
        int flag = 1;
        for(int j=0;j<20;j++){          //检测是否有连续座位可出票
            if(v[j].size() >= cmd){
                for(int k=0;k<cmd;k++){
                    cout << v[j][k];
                    if(k < cmd-1) cout << " ";
                    else cout << endl;
                    flag = 0;
                }
                v[j].erase(v[j].begin(),v[j].begin()+cmd);
                break;
            }
        }
        if(flag){   //没有连续座位，按座位编号从小到大输出
            for(int j=0;j<20;j++){
                for(vector<int>::iterator it=v[j].begin();it != v[j].end() && cmd>0;){
                    cout << *it;
                    cmd--;
                    if(cmd != 0) cout << " ";
                    else cout << endl;
                    v[j].erase(it);
                }
                if(cmd == 0) break;
            }
        }
    }
    return 0;
}
