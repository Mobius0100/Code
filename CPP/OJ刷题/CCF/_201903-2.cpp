/*
    ：计算给出算式是否为二十四
      可以使用栈，也可以双循环；前者更通用，可用于任何计算式
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,ans=0;
    char sign[3];
    int num[4],num1[3],num2[2];

    cin >> n;
    for(int i=0;i<n;i++){
        scanf("%d%c%d%c%d%c%d",&num[0],&sign[0],&num[1],&sign[1],&num[2],&sign[2],&num[3]);
        for(int j=0;j<3;j++){  
            if(sign[j] == 'x'){
                num1[j] = num[j]*num[j+1];
            }
            else if(sign[j] == '/'){
                num1[j] = num[j]*num[j+1];
            }
            else num1[j] = num[j];

        }        
    }
    
    return 0;
}


