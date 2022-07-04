#include "stack.h"
#include "lstack.h"
#include<iomanip>
#include<iostream>

using namespace std;
void print(LStack<int> &A,int n);

int main(){
	int n;
	LStack<int> S1(100);
  	cout<<"**************************"<<endl; 
  	cout<<"*��ʽջ�и�������������ʾ*"<<endl;
	cout<<"**************************"<<endl<<endl;
  	cout<<"����ʽջ���������Ԫ��12��15��9��48��55"<<endl;
  	//������ʽջ�е�push���� 
  	S1.push(12);
  	S1.push(15);
  	S1.push(9);
  	S1.push(48);
  	S1.push(55);
  	cout<<"���Ԫ�غ���ʽջ������Ϊ��"<<endl; 
  	n=S1.length(); //��ȡ��ʽջ���� 
  	print(S1,n);
  	cout<<"��ǰ��ʽջ����Ϊ:"<<endl<<S1.length()<<endl<<endl; 
  	cout<<"�鿴��ʽջ��ջ��Ԫ��:"<<endl<<S1.topValue()<<endl<<endl;
  	cout<<"ɾ����ǰλջ��Ԫ��" <<endl<<endl;
  	//������ʽջ�е�pop���� 
  	S1.pop(); 
  	cout<<"ɾ��Ԫ�غ���ʽջ�е�����Ϊ��"<<endl;
  	n=S1.length(); //��ȡ��ʽջ����
	print(S1,n);
	//����clear����
	cout<<"���˳��ջ��ջ������"<<endl;
	S1.clear();
	n=S1.length(); //��ȡ��ʽջ����
	print(S1,n); 
}
/***********************
*function of print
*��ӡ��ʽջ��Ԫ��
************************/ 
void print(LStack<int> &A,int n){
	int i;
	int t,a;
	LStack<int> B(100);//ջ�ĸ����壬����
	t=A.length();
	for(i=0;i<t;i++){ //����ջ 
		a=A.pop(); 
		B.push(a);
	}
	for(i=0;i<t;i++){ //��ԭջ 
		a=B.pop(); 
		cout<<a<<" ";
		A.push(a);
	}
	cout<<endl<<endl;
}

