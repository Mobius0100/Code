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
  	cout<<"*链式栈中各个基本操作演示*"<<endl;
	cout<<"**************************"<<endl<<endl;
  	cout<<"向链式栈中依次添加元素12、15、9、48、55"<<endl;
  	//调用链式栈中的push操作 
  	S1.push(12);
  	S1.push(15);
  	S1.push(9);
  	S1.push(48);
  	S1.push(55);
  	cout<<"添加元素后链式栈中内容为："<<endl; 
  	n=S1.length(); //获取链式栈长度 
  	print(S1,n);
  	cout<<"当前链式栈长度为:"<<endl<<S1.length()<<endl<<endl; 
  	cout<<"查看链式栈中栈顶元素:"<<endl<<S1.topValue()<<endl<<endl;
  	cout<<"删除当前位栈顶元素" <<endl<<endl;
  	//调用链式栈中的pop操作 
  	S1.pop(); 
  	cout<<"删除元素后链式栈中的内容为："<<endl;
  	n=S1.length(); //获取链式栈长度
	print(S1,n);
	//调用clear操作
	cout<<"清空顺序栈后栈中内容"<<endl;
	S1.clear();
	n=S1.length(); //获取链式栈长度
	print(S1,n); 
}
/***********************
*function of print
*打印链式栈中元素
************************/ 
void print(LStack<int> &A,int n){
	int i;
	int t,a;
	LStack<int> B(100);//栈的复制体，倒序
	t=A.length();
	for(i=0;i<t;i++){ //复制栈 
		a=A.pop(); 
		B.push(a);
	}
	for(i=0;i<t;i++){ //还原栈 
		a=B.pop(); 
		cout<<a<<" ";
		A.push(a);
	}
	cout<<endl<<endl;
}

