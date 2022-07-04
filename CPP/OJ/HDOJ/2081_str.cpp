/*
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string str;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str;
        cout << "6" << str.substr(6,5) << endl;
    }
    
    return 0;
}
