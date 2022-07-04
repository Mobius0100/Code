#include "stack.h"
#include <assert.h>
// This is the declaration for AStack. 
// Array-based stack implementation 顺序栈的实现
template <typename E> class AStack: public Stack<E> {
private:
  int maxSize;              // Maximum size of stack 顺序栈的容量
  int top;                 // Index for top element 栈顶元素的索引地址 
  E *listArray;           // Array holding stack elements 存放顺序栈元素的数组 

public:
  AStack(int size =100)   // Constructor 构造函数 
    { maxSize = size; top = 0; listArray = new E[size]; }

  ~AStack() { delete [] listArray; }   // Destructor 析构函数 

  void clear() { top = 0; }           // Reinitialize 初始化 

  void push(const E& it) {          // Put "it" on stack  "it"入栈
    assert(top != maxSize);        // "Stack is full" 若栈溢出则断言终止程序 
    listArray[top++] = it;
  }

  E pop() {                // Pop top element 删除并返回栈顶元素 
    assert(top != 0);     //"Stack is empty"
    return listArray[--top];
  }

  const E& topValue() const {  // Return top element 返回栈顶元素 
    assert(top != 0);         // "Stack is empty" 若栈空则断言终止程序 
    return listArray[top-1];
  }

  int length() const { return top; }  // Return length 返回栈的长度 
};
