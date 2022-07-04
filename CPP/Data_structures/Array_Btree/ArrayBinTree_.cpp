#include <iostream>
#include<iomanip>
#include <string>
#include "ANode.h" 
#include "ABinTree.h"
using namespace std;
typedef char E;
char c[50];
string s1,s2;
ANode a;
ABinTree T;

//建树操作 以层次遍历输入 
int CreateBiTree(string s){
	strcpy(c,s.c_str());
	for(int i=0;c[i]!='\0';i++){
		a.setLeft(i);
		a.setRight(i);	
		a.setElement(c[i]);
		T.nodeArray.push_back(a);
	}
	return 0;//返回根节点下标 
}
int main()
{
	cin >> s1;
	cin >> s2;
	if(s1.find(s2) != string::npos) cout << "yes";
	else cout << "no";

	return 0;
}
