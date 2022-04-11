/*

    十六进制可以直接输入输出，但负数要单独处理
    16位 16进制的数转换成二进制是64位

#include<stdio.h>
int main()
{
	long long n,m,v;
	while(scanf("%llx%llx",&n,&m)==2)     //注意接收格式llx
	{
		v=n+m;
		if(v<0)
		{
			v=-v;
			printf("-%llX\n",v);	
		}
		else
		printf("%llX\n",v);	
	}  
     return 0;
 } 


*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

typedef long long ll;

char Hex[20] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

ll hextoten(string s){
    string str = s;
    reverse(str.begin(), str.end());    //反转字符串
    ll sum = 0;
    int flag = 0;

    for(int i=0;i<str.length();i++){
        if(str[i] == '-') {
            flag = 1;
            continue;
        }
        if(str[i] == '+') continue;
        int k=0;
        while(str[i] != Hex[k]) k++;
        sum += k*pow(16,i);   //x的y次幂 pow(x,y)

    }

    if(flag) sum = -sum;
    return sum;

}

string numtohex(ll sum){
    if(sum < 0){
        cout << '-';
        sum = -sum;
    }

    int z[40], num = 0;
    //进制转换
    do{
        z[num++] = sum % 16;
        sum = sum / 16;
    }while(sum != 0);

    string str;
    for(int i=num-1; i >=0; i--){
        str += Hex[z[i]];
    }

    return str;
}

int main()
{
    string str1,str2,ans;
    ll num1,num2;

    while(cin >> str1 >> str2){
        
        ll sum=0;
        num1 = hextoten(str1);
        num2 = hextoten(str2);
        sum = num1 + num2;
        ans = numtohex(sum);
        cout << ans << endl;
    }

    return 0;
}
