#ifndef QUEUE
#define QUEUE
// Abstract queue class ���г�����
template <typename E> class Queue {
private:
  void operator =(const Queue&) {}    
  Queue(const Queue&) {}        

public:
  Queue() {}         // Default ���캯��
  virtual ~Queue() {} 	// Base destructor ��������

  // Reinitialize the queue.  The user is responsible for
  // reclaiming the storage used by the queue elements.
// �������ö��С��û��������ʹ�õĴ洢����Ԫ�ء�
  virtual void clear() = 0;

  // Place an element at the rear of the queue. �ڶ��еĺ������Ԫ�� 
  // it: The element being enqueued.  it:Ҫ��������е�Ԫ��
  virtual void enqueue(const E&) = 0;

  // Remove and return element at the front of the queue. ɾ���������ڶ���ͷ����Ԫ��
  virtual E dequeue() = 0;

  // Return: A copy of the front element. ���ض���ͷ��Ԫ�أ���ɾ����
  virtual const E& frontValue() const = 0;

  // Return: The number of elements in the queue. ���ض�����Ԫ�ظ���
  virtual int length() const = 0;
};
#endif

