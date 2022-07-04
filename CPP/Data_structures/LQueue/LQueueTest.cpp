#include "queue.h"
#include "LQueue.h"
#include<iomanip>
#include<iostream>

using namespace std;
//void print(AQueue<int>& AQ,int n);

// Main routine for array-based queue driver class
int main(){
	int n;
	LQueue<int> Q1(100);
  	cout<<"**************************"<<endl; 
  	cout<<"*链式队列中各个基本操作演示*"<<endl;
	cout<<"**************************"<<endl<<endl;
  	cout<<"向链式队列中依次添加元素12、24、5、90、7、33"<<endl;
  	//调用链式队列中的enqueue操作 
  	Q1.enqueue(12);
  	Q1.enqueue(24);
  	Q1.enqueue(5);
  	Q1.enqueue(90);
  	Q1.enqueue(7);
  	Q1.enqueue(33);

  	cout<<"添加元素后链式队列长度为："; 
  	cout<<Q1.length()<<endl<<endl;//获取链式队列长度 
  	
  	while(Q1.length()!=0){
  		cout<<"获得队列中第一个元素："<<Q1.frontValue()<<endl;
  		//调用链式队列中的dequeue操作 
		cout<<"第一个元素"<<Q1.dequeue()<<"出队列"<<endl;
		cout<<"当前链式队列长度为："<<Q1.length()<<endl<<endl;
	}
}

