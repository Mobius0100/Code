/*
    图形输出题
    抓住规律，注意格式
*/
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n,cnt=0;   //cnt用来控制输出空行
    char c;
    while(cin >> c){
        if(c == '@') break;
        cin >> n;
        if(cnt) printf("\n");

        for(int i=0; i<n; i++){
            for(int j=1; j<n-i; j++) printf(" ");
            printf("%c",c);
            if(i == n-1) {
                int cnt = 2*n-2;
                while(cnt--) printf("%c",c);
            }
            else if(i > 0){
                int cnt = 2*i-1;
                while(cnt--) printf(" ");
                printf("%c",c);
            }
            printf("\n");
        }
        cnt++;
    }
    return 0;
}
