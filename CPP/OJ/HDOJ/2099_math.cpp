/*
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int a,b;

    while(cin >> a >> b){
        if(a == 0 && b == 0) break;

        int k = a*100;
        int flag = 0;
        for(int i=0;i<100;i++){
            if((k+i) % b == 0){
                if(flag == 1) printf(" "); 
                printf("%02d",i);
                flag = 1;
            }
        }
        cout << endl;
    }
    return 0;
}
