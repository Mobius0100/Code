#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include "BiNode.h" 
#include "BinTree.h"
using namespace std;
typedef char E;
char c[50];
int count=0;
string s;
BiNode* r;
BinTree T;

//���� 
BiNode* CreateBiTree(char ch){
	BiNode* rt;
	if(ch=='#')  rt=NULL;
	else{
		rt=new BiNode;
		rt->setElement(ch);
		ch=c[++count];
		rt->setLeft(CreateBiTree(ch));
		ch=c[++count];
		rt->setRight(CreateBiTree(ch));
	}
	//���ø��ڵ� 
	T.setroot(rt);
	return rt;
}
	
int main()
{

	char ch;
	int depth;
	int num;
    printf("please input the tree: ");
    cout<<"��ǰ�������˳�����룬�սڵ���#����,��AB#D##CE##F##"<<endl; 
    cin>>s;
    strcpy(c,s.c_str());
    r=CreateBiTree(c[0]);
   
    cout<<"�ж����Ƿ��ǿ�����";
    if(T.BiTreeEmpty(r))
        cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    
    cout<<"ǰ�������"; 
    T.preorder(r);
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
