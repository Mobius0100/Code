/*
	:求最大连续子序列和，并输出其首尾数字
	思路：状态转移方程 dp[i] = max(num[i],num[i]+dp[i-1]);
		  若dp[i]更新为本身，则最大连续子序列首位为当前位置
		  dp[i] == num[i]?  -> index[i] = i; else index[i] = index[i-1];
*/
#include <bits/stdc++.h>

using namespace std;

const int M = 10010;

int main()
{
	int n,flag=0;
	int dp[M]={0},num[M]={0},index[M]={0};
	cin >> n;
	
	for(int i=0;i<n;i++){
		cin >> num[i];
		if(num[i] >= 0) flag = 1;
	}
	
	dp[0] = num[0];
	for(int i=1;i<n;i++){
		dp[i] = max(num[i], dp[i-1] + num[i]);
		if(dp[i] == num[i]) index[i] = i;
		else index[i] = index[i-1];
	}
	
	if(flag){
		int k=0;
		for(int i=1;i<n;i++){
			if(dp[i] > dp[k]) k = i;
		}
		
		printf("%d %d %d\n",dp[k],num[index[k]],num[k]);
	}
	else{
		printf("0 %d %d\n",num[0],num[n-1]);
	}
	
	return 0;
}
