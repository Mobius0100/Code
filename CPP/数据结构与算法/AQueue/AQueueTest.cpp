#include "queue.h"
#include "AQueue.h"
#include<iomanip>
#include<iostream>

using namespace std;
//void print(AQueue<int>& AQ,int n);

// Main routine for array-based queue driver class
int main(){
	int n;
	AQueue<int> Q1(100);
  	cout<<"**************************"<<endl; 
  	cout<<"*顺序队列中各个基本操作演示*"<<endl;// Declare some sample lists
	cout<<"**************************"<<endl<<endl;
  	cout<<"向顺序队列中依次添加元素12、24、5、90、7、33"<<endl;
  	//调用顺序队列中的enqueue操作 
  	Q1.enqueue(12);
  	Q1.enqueue(24);
  	Q1.enqueue(5);
  	Q1.enqueue(90);
  	Q1.enqueue(7);
  	Q1.enqueue(33);
  	cout<<"添加元素后顺序队列长度为："; 
  	cout<<Q1.length()<<endl<<endl;//获取顺序队列长度 
  	
  	while(Q1.length()!=0){
  		cout<<"获得队列中第一个元素："<<Q1.frontValue()<<endl;
		cout<<"第一个元素"<<Q1.dequeue()<<"出队列"<<endl;
		cout<<"当前顺序队列长度为："<<Q1.length()<<endl<<endl;
	}
}


