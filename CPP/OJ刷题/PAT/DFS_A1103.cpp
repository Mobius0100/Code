/*
    :给定N,K,P，将N表示成K个整数的P次方和，优先选择底数和最大的，其次底数序列字典序最大的；
    注意：预先计算出每次底数增加的幂，然后递减枚举，可以保证字典序最大的先被选中，还可以提高效率；
    
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
int maxSumSqu = -1;
int n,k,p;
vector<int > temp,ans,fac;


void init(){
    int num=0,temp=0;
    while(temp <= n){
        fac.push_back(temp);
        temp = pow(++num,p);
    }
}

void DFS(int index,int nowK, int sum, int sumSqu){
	if(nowK == k && sum == n){          //判断边界
		if(sumSqu > maxSumSqu){
			maxSumSqu = sumSqu;
			ans = temp;
		}
		return;
	}
	
	if(nowK > k || sum > n) return;    //判断边界
	if(index - 1 >= 0){
        temp.push_back(index);

        DFS(index,nowK+1,sum+fac[index], sumSqu+index);
        temp.pop_back();    //恢复上次状态

        //不选择该数
        DFS(index-1,nowK,sum,sumSqu); 
    }
	
}

int main()
{
    cin >> n >> k >> p;
    init();
    DFS(fac.size() - 1,0,0,0);

    if(ans.size() > 0){
        printf("%d = ",n);
        for(vector<int>::iterator it = ans.begin();it != ans.end();it++){
            cout << *it << "^" << p;
            if(it != ans.end() - 1) cout << " + ";
        }
        cout << endl;
    }
    else cout << "Impossible" << endl;
    return 0;
}
