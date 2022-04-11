#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
	
	double x1,x2,y1,y2,len;
	
	while(cin >> x1 >> y1 >> x2 >> y2)
	{
		double t1=x2-x1,t2=y2-y1;
		len = sqrt(t1*t1 + t2*t2);
		
		printf("%.2f\n",len); 
	}
	
	return 0;
	
}
