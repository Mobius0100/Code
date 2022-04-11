#include <iostream>

using namespace std;

void sw(char &x, char &y)
{
    char t;
    t = x;
    x = y;
    y = t;
}

int main()
{
    char a,b,c,t;
    while(cin >> a >> b >> c)
    {
    	
    	if(a > b) sw(a,b);
    	if(a > c) sw(a,c);
    	if(b > c) sw(b,c);

    	cout << a << " " << b << " " << c <<endl;

    }

    return 0;
}
