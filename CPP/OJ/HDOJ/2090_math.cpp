/*
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;

const int maxn = 100010;

struct Cai{
    string name;
    double cnt,price;
}cai[maxn],tmp;

int main()
{

    double sum = 0.0;

    while(cin >> tmp.name >> tmp.cnt >> tmp.price){
        if(tmp.name == "") break;

        sum += (tmp.cnt * tmp.price);
    }

    printf("%0.1llf\n",sum);
    return 0;
}
