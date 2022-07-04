#include <bits/stdc++.h>

using namespace std;

int ans[2][3] = {0};
int mp[2][3] = {0};

int main()
{
    int n;
    char Jia,Yi;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> Jia >> Yi;
        if(Jia == Yi) ans[0][1]++,ans[1][1]++;
        else if(Jia == 'C' && Yi == 'J') ans[0][0]++,ans[1][2]++,mp[0][1]++;
        else if(Jia == 'J' && Yi == 'B') ans[0][0]++,ans[1][2]++,mp[0][2]++;
        else if(Jia == 'B' && Yi == 'C') ans[0][0]++,ans[1][2]++,mp[0][0]++;
        else if(Yi == 'C' && Jia == 'J') ans[1][0]++,ans[0][2]++,mp[1][1]++;
        else if(Yi == 'J' && Jia == 'B') ans[1][0]++,ans[0][2]++,mp[1][2]++;
        else if(Yi == 'B' && Jia == 'C') ans[1][0]++,ans[0][2]++,mp[1][0]++;
    }

    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            cout << ans[i][j];
            if(j < 2) cout << " ";
            else cout << endl;
        }
    }
    for(int i=0;i<2;i++){
        int mx=-1;
        int index=-1;
        for(int j=0;j<3;j++){
            if(mp[i][j] > mx) mx = mp[i][j],index=j;
        }

        switch (index)
        {
            case 0:cout << "B ";break;
            case 1:cout << "C ";break;
            case 2:cout << "J ";break;
        }
    }
    

    
    return 0;
}