/*
*/
#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;

struct Person{
    string name;
    int year,month,day;
}person[maxn],minP,maxP,tmp;

bool cmp(Person a,Person b){
    if(a.year != b.year) return a.year < b.year;
    else if(a.month != b.month) return a.month < b.month;
    else return a.day < b.day;
}

int main()
{
    int n,cnt=0;
    minP.year=2014,minP.month=9,minP.day=6;
    maxP.year=1814,maxP.month=9,maxP.day=6;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp.name;
        scanf("%d/%d/%d",&tmp.year,&tmp.month,&tmp.day);
        if(tmp.year == minP.year && tmp.month <=minP.month && tmp.day <= minP.day){
            person[cnt++] = tmp;
        }
        else if(tmp.year == maxP.year && tmp.month >= maxP.month && tmp.day >= maxP.day){
            person[cnt++] = tmp;
        }
        else if(tmp.year < minP.year && tmp.year > maxP.year){
            person[cnt++] = tmp;
        }
    }

    sort(person,person+cnt,cmp);

    cout << cnt << " " << person[0].name << " " << person[cnt-1].name << endl;

    return 0;
}
