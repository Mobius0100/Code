/*
    涉及字符串输出控制，字符串转数字，表格形式，可作为典型例题；

*/

#include <algorithm>
#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 10010;

struct Student{
    char name[10];
    int ac_cnt,tscore;
}stu[maxn];

//输入：字符串s，字符串的起始和末尾位置
//输出：转换后的数字
int str2num(string s, int start, int end){
    int sum = 0;
    for(int i=start; i<end; i++){
        int k = s[i] - '0';
        sum = sum*10 + k;
    }

    return sum;
}

bool cmp(Student a, Student b){
    if(a.ac_cnt != b.ac_cnt) return a.ac_cnt > b.ac_cnt;
    else if(a.tscore != b.tscore) return a.tscore < b.tscore;
    else return a.name < b.name;
}

int main()
{
    int num,pun_score;

    cin >> num >> pun_score;

    int index = 0;
    while(scanf("%s",&stu[index].name) != EOF){
        stu[index].ac_cnt = 0;
        stu[index].tscore = 0;

        string str[12];
        for(int i=0; i<num; i++){
            cin >> str[i];

            if(str[i][0] == '-' || str[i][0] == '0') continue;

            stu[index].ac_cnt++;

            if(str[i].find('(') == string::npos){
                stu[index].tscore += str2num(str[i], 0, str[i].length());
            } else {
                stu[index].tscore += str2num(str[i], 0, str[i].find('('));
                int k = str2num(str[i], str[i].find('(')+ 1, str[i].find(')'));
                stu[index].tscore += k*pun_score;
            }
        }

        index++;
    }

    sort(stu, stu+index, cmp);

    for(int i=0; i<index; i++){
        //字符串输出控制，-表示左对齐，默认右对齐
        printf("%-10s %2d %4d\n",stu[i].name, stu[i].ac_cnt, stu[i].tscore);
    }
    

    return 0;
}
