#ifndef QUEUE
#define QUEUE
// Abstract queue class 队列抽象类
template <typename E> class Queue {
private:
  void operator =(const Queue&) {}    
  Queue(const Queue&) {}        

public:
  Queue() {}         // Default 构造函数
  virtual ~Queue() {} 	// Base destructor 析构函数

  // Reinitialize the queue.  The user is responsible for
  // reclaiming the storage used by the queue elements.
// 重新启用队列。用户负责回收使用的存储队列元素。
  virtual void clear() = 0;

  // Place an element at the rear of the queue. 在队列的后面添加元素 
  // it: The element being enqueued.  it:要被加入队列的元素
  virtual void enqueue(const E&) = 0;

  // Remove and return element at the front of the queue. 删除并返回在队列头部的元素
  virtual E dequeue() = 0;

  // Return: A copy of the front element. 返回队列头部元素（不删除）
  virtual const E& frontValue() const = 0;

  // Return: The number of elements in the queue. 返回队列中元素个数
  virtual int length() const = 0;
};
#endif

