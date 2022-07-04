#include "stack.h"
#include "astack.h"
#include<iomanip>
#include<iostream>

using namespace std;
void print(AStack<int> &A,int n);

int main(){
	int n;
	AStack<int> S1(100);
  	cout<<"**************************"<<endl; 
  	cout<<"*顺序栈中各个基本操作演示*"<<endl;
	cout<<"**************************"<<endl<<endl;
  	cout<<"向顺序栈中依次添加元素12、15、9、48、55"<<endl;
  	//调用顺序栈中的push操作 
  	S1.push(12);
  	S1.push(15);
  	S1.push(9);
  	S1.push(48);
  	S1.push(55);
  	cout<<"添加元素后顺序栈中内容为："<<endl; 
  	n=S1.length(); //获取顺序栈长度 
  	print(S1,n);
  	cout<<"当前顺序栈长度为:"<<endl<<S1.length()<<endl<<endl; 
  	cout<<"查看顺序栈中栈顶元素:"<<endl<<S1.topValue()<<endl<<endl;
  	cout<<"删除当前栈顶元素" <<endl<<endl;
  	//调用顺序栈中的pop操作 
  	S1.pop(); 
  	cout<<"删除元素后顺序栈中的内容为："<<endl;
  	n=S1.length(); //获取顺序栈长度
	print(S1,n);
	//调用clear操作
	cout<<"清空顺序栈后栈中内容:"<<endl;
	S1.clear();
	n=S1.length(); //获取顺序栈长度
	print(S1,n); 
}
/***********************
*function of print
*打印顺序栈中元素
************************/ 
void print(AStack<int> &A,int n){
	int i;
	int t,a;
	AStack<int> B(100);
	t=A.length();
	for(i=0;i<t;i++){
		a=A.pop(); 
		B.push(a);
	}
	for(i=0;i<t;i++){
		a=B.pop(); 
		cout<<a<<" ";
		A.push(a);
	}
	cout<<endl<<endl;
}
