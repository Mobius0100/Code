/*
    进制转换
*/
#include <cstdio>
#include <iostream>

using namespace std;

char mp[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

void change(int num, int k){
    int z[40], index=0;

    if(num < 0){
        cout << '-';
        num = -num;
    }

    do{
        z[index++] = num % k;
        num = num / k; 
    }while(num > 0);

    for(int i=index-1; i >= 0; i--){
        cout << mp[z[i]];
    }
    cout << endl;

}
int main()
{
    int n,r;
    
    while(cin >> n >> r){
        change(n,r);
    }

    return 0;
}
