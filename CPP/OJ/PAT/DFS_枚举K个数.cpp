/*
    给定一组序列，从中选择K个数，使和刚好为X，如果有多种方案，从中选择元素平方和最大的一组 
*/
#include <bits/stdc++.h>

using namespace std;

const int maxn = 10000; 
int n,k,x,maxSumSqu = -1,A[maxn];
vector<int> temp,ans;

void DFS(int index,int nowK, int sum, int sumSqu){
	if(nowK == k && sum == x){          //判断边界
		if(sumSqu > maxSumSqu){
			maxSumSqu = sumSqu;
			ans = temp;
		}
		return;
	}
	
	if(index == n || nowK > k || sum > x) return;    //判断边界
	
	temp.push_back(A[index]);
    
    //选择该数
    //若改成每个数可选择多次，则可改成：
    //DFS(index,nowK+1,sum+A[index],sumSqu+A[index]*A[index]);
	DFS(index+1,nowK+1,sum+A[index],sumSqu+A[index]*A[index]);
	temp.pop_back();    //恢复上次状态

    //不选择该数
	DFS(index+1,nowK,sum,sumSqu); 
}

int main()
{
	cin >> n >> k >> x;
	for(int i=0;i<n;i++) cin >> A[i];
	DFS(0,0,0,0);
    for(auto it:ans) cout << it << " ";
	// for(vector<int>::iterator it = ans.begin(); it != ans.end(); it++){
	// 	cout << *it << " ";
	// }   
}
