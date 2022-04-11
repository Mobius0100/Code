// This is the declaration for Aqueue. 
// Array-based queue implementation. 基于数组的顺序队列AQueue
#include<assert.h>
template <typename E> class AQueue: public Queue<E> {
private:
  int maxSize;             	// Maximum size of queue 队列最大容量
  int front;               	// Index of front element 头部的索引 
  int rear;                  	// Index of rear element 尾部索引
  E *listArray;           		// Array holding queue elements 数组存储队列元素

public:
  AQueue(int size =100) {  // Constructor 构造函数
// Make list array one position larger for empty slot 
//使数组比队列容量多一个位置做为空槽
    maxSize = size+1;
    rear = 0;  front = 1;
    listArray = new E[maxSize];
  }

  ~AQueue() { delete [] listArray; } // Destructor 析构函数

  void clear() { rear = 0; front = 1; } // Reinitialize 重新预置

  void enqueue(const E& it) {  	// Put "it" in queue.  it入队列
    assert(((rear+2) % maxSize) != front);	// "Queue is full" 队满则断言终止
    rear = (rear+1) % maxSize; 	// Circular increment 头部索引在队列范围内循环加1
    listArray[rear] = it;
  }

  E dequeue() {          	// Take element out. 一个元素出队列
    assert(length() != 0);		// "Queue is empty" 队空则断言终止
    E it = listArray[front];
    front = (front+1) % maxSize; // Circular increment 尾部索引在队列范围内循环加1    return it;
  }

  const E& frontValue() const { 	// Get front value 获得头部元素
    assert(length() != 0);		//"Queue is empty"队空则断言终止
    return listArray[front];
  }

  virtual int length() const    	// Return length 返回队列长度
    { return ((rear+maxSize) - front + 1) % maxSize; }
};

