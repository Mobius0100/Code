#include <iostream>
#include<iomanip>
#include "ANode.h" 
#include "ABinTree.h"
using namespace std;
typedef char E;
char c[50];
string s;
ANode a;
ABinTree T;

//�������� �Բ�α������� 
int CreateBiTree(string s){
	strcpy(c,s.c_str());
	for(int i=0;c[i]!='\0';i++){
		a.setLeft(i);
		a.setRight(i);	
		a.setElement(c[i]);
		T.nodeArray.push_back(a);
	}
	return 0;//���ظ��ڵ��±� 
}
int main()
{
	int r;
	int depth;
	int num;
    cout<<"��ʾ��"<<endl
    	<<"���ַ�����ʽ����Ҫ�����Ķ�����ʱ������α�����˳�����룬���еĿսڵ���#����"<<endl
		<<"ע�⣡Ҫ���뵽�����Ҷ�ڵ����һ�㣬���Ҹò�Ԫ��Ϊ2^i��#���ţ�"<<endl
		<<"����ABC#DEF########"<<endl
		<<"�����룺";
  cin>>s; 
	//���� 
	r=CreateBiTree(s);
	cout<<"-----------------------------------"<<endl; 
  cout<<"�ж����Ƿ��ǿ�����";
  if(T.BiTreeEmpty(r))
      cout<<"����Ϊһ�ÿ���"<<endl;
  else cout<<"���ǿ���"<<endl;
  
 cout<<"ǰ�������"; 
  T.preorder(T.Root());
  cout<<endl;

  cout<<"���������";
  T.Inorder(r);
  cout<<endl;

  cout<<"���������";
  T.postorder(r);
  cout<<endl;

  cout<<"��α�����";
  T.LevelOrderTraverse(r);
  cout<<endl;
  
  cout<<"������ȣ�";
  depth=T.BiTreeDepth(r);
  cout<<depth<<endl;
  
  cout<<"���Ľ�������";
  num=T.count(r);
  cout<<num<<endl;

	return 0;
}
