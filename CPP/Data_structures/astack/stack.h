#ifndef STACK
#define STACK
template <typename E> class Stack {
private:
  void operator =(const Stack&) {}     // Protect assignment
  Stack(const Stack&) {}         // Protect copy constructor

public:
  Stack() {}                       // Default constructor构造函数
  virtual ~Stack() {}              // Base destructor析构函数

  // Reinitialize the stack.  The user is responsible for
  // reclaiming the storage used by the stack elements.初始化栈 ，用户负责回收被使用来存储栈元素的空间
  virtual void clear() = 0;

  // Push an element onto the top of the stack.
  // it: The element being pushed onto the stack.在栈顶压入“it”
  virtual void push(const E& it) = 0;

  // Remove the element at the top of the stack.
  // Return: The element at the top of the stack.删除并返回栈顶元素
  virtual E pop() = 0;

  // Return: A copy of the top element.返回栈顶元素
  virtual const E& topValue() const = 0;

  // Return: The number of elements in the stack.返回当前栈的长度 
  virtual int length() const = 0;
};
#endif
