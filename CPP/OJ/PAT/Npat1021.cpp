/*
*/
#include <bits/stdc++.h>

using namespace std;

int Rate[20] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char M[11] = {'1','0','X','9','8','7','6','5','4','3','2'};

int check(string s)
{
    int a[17];
    for(int i=0;i<17;i++)
        a[i]=s[i]-'0';
    int ans=0;
    for(int i=0;i<17;i++)
        ans+=a[i]*Rate[i];
    ans=ans%11;
    if(M[ans]==s[17])
        return 1;
    else
        return 0;
}

int main()
{
    string num;
    int N,cnt=0;

    cin >> N ;
    
    for(int i=0;i<N;i++){
        cin >> num;
        int sum=0,flag=0;
        for(int j=0;j<17;j++){
            if(!isdigit(num[j])){
                cout << num << endl;
                cnt++;
            }
        }
        if(flag) continue;
        sum = sum%11;
        if(M[sum] == num[17]) continue;
        else{
            cnt++;
            cout << num << endl;
        }
    }

    if(cnt == 0) cout << "All passed" <<endl;
    

    return 0;
}
