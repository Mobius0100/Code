/*
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <stack>
#include <vector>

using namespace std;

const int maxn = 100;

stack<int> s1,s2,s3;
vector<int> cnt;

void hnt(int num, stack<int> source, stack<int> target, stack<int> auxiliary){
    if(num == 1){
        target.push(source.top());
        cnt[source.top()]++;
        source.pop();
    } else {
        hnt(num-1, source, auxiliary, target);
        target.push(source.top());
        cnt[source.top()]++;
        source.pop();
        hnt(num-1, auxiliary, target, source);
    }
}

int main()
{
    int m,n,k;
    cin >> m;
    for(int count = 0; count < m; count++){
        cin >> n >> k;

        cnt.clear();
        for(int i=n;i>=1;i--){
            s1.push(i);
        }
        hnt(n,s1,s2,s3);
        cout << cnt[k] << endl;
    }

    return 0;
}
