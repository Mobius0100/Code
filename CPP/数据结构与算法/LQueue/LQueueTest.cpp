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
  	cout<<"*��ʽ�����и�������������ʾ*"<<endl;
	cout<<"**************************"<<endl<<endl;
  	cout<<"����ʽ�������������Ԫ��12��24��5��90��7��33"<<endl;
  	//������ʽ�����е�enqueue���� 
  	Q1.enqueue(12);
  	Q1.enqueue(24);
  	Q1.enqueue(5);
  	Q1.enqueue(90);
  	Q1.enqueue(7);
  	Q1.enqueue(33);

  	cout<<"���Ԫ�غ���ʽ���г���Ϊ��"; 
  	cout<<Q1.length()<<endl<<endl;//��ȡ��ʽ���г��� 
  	
  	while(Q1.length()!=0){
  		cout<<"��ö����е�һ��Ԫ�أ�"<<Q1.frontValue()<<endl;
  		//������ʽ�����е�dequeue���� 
		cout<<"��һ��Ԫ��"<<Q1.dequeue()<<"������"<<endl;
		cout<<"��ǰ��ʽ���г���Ϊ��"<<Q1.length()<<endl<<endl;
	}
}

