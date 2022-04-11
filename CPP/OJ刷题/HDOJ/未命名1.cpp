#include<stdio.h>
#include<iostream>
#include <string>

using namespace std;

int main()
{
 	   int n;
 	   string str;
 	   
		cin >> n;
 	   
 	   for(int i=0;i<n;i++)
 	   {
 	   		int arr[5] = {0},len=0;
 	   		getline(cin,str);
 	   		
 	   		len = str.length();
 	   		for(int j=0;j<len;j++)
 	   		{
 	   			switch(str[j] - 'a')
 	   			{
 	   				case 0:arr[0]++;break;
 	   				case ('e'-'a'):arr[1]++;break;
 	   				case 8:arr[2]++;break;
 	   				case 14:arr[3]++;break;
 	   				case 20:arr[4]++;break;
 	   			}
 	   		}
 	   		
   		 	cout << "a:" << arr[0] << endl;
   			cout << "e:" << arr[1] << endl;
   			cout << "i:" << arr[2] << endl;
   			cout << "o:" << arr[3] << endl;
   			cout << "u:" << arr[4] << endl;
   			
   			if(i != n-1) cout << endl;
 	   }
 	   
 	   return 0;
}

