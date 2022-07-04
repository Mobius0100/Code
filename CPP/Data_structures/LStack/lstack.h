#include "link.h"
#include "stack.h"
#include <assert.h>

template <typename E> class LStack: public Stack<E> {
private:
  Link<E>* top;                 // Pointer to first element 指向第一个元素
  int size;                     // Number of elements 元素数目

public:
  LStack(int sz =100)             // Constructor 构造函数 
    { top = NULL; size = 0; }

  ~LStack() { clear(); }          // Destructor 析构函数 

  void clear() {                  // Reinitialize 初始化 
    while (top != NULL) {         // Delete link nodes 删除节点元素 
      Link<E>* temp = top;
      top = top->next;
      delete temp;
    }
    size = 0;
  }

  void push(const E& it) { // Put "it" on stack "it"入栈 
    top = new Link<E>(it, top);
    size++;
  }

  E pop() {                // Remove "it" from stack 删除栈顶元素 
    assert(top != NULL);   // "Stack is empty" 若栈空则终止程序 
    E it = top->element;
    Link<E>* ltemp = top->next;
    delete top;
    top = ltemp;
    size--;
    return it;
  }

  const E& topValue() const { // Return top value 返回栈顶元素 
    assert(top != 0);         // "Stack is empty" 若栈空则终止程序 
    return top->element;
  }

  int length() const { return size; } // Return length 返回栈长度 
};
