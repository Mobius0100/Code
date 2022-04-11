/*
    :日期计算，指定年份和天数；输出是几月几号
*/
#include <bits/stdc++.h>

using namespace std;

int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

bool is_ry(int year)
{
    if(year % 400 == 0) return true;
    if(year % 4 == 0 && year % 100 != 0) return true;
    return false;
}

int main()
{
    int y,d,month=1;
    cin >> y >> d;
    
    if(is_ry(y)) days[1]++;
    for(int i=0;i<12;i++){
        if(d-days[i] > 0){
            month++;
            d -= days[i];
        }
        else break;
    }

    printf("%d\n%d",month,d);
    return 0;
}
