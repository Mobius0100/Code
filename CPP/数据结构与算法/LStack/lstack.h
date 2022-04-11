#include "link.h"
#include "stack.h"
#include <assert.h>

template <typename E> class LStack: public Stack<E> {
private:
  Link<E>* top;                 // Pointer to first element ָ���һ��Ԫ��
  int size;                     // Number of elements Ԫ����Ŀ

public:
  LStack(int sz =100)             // Constructor ���캯�� 
    { top = NULL; size = 0; }

  ~LStack() { clear(); }          // Destructor �������� 

  void clear() {                  // Reinitialize ��ʼ�� 
    while (top != NULL) {         // Delete link nodes ɾ���ڵ�Ԫ�� 
      Link<E>* temp = top;
      top = top->next;
      delete temp;
    }
    size = 0;
  }

  void push(const E& it) { // Put "it" on stack "it"��ջ 
    top = new Link<E>(it, top);
    size++;
  }

  E pop() {                // Remove "it" from stack ɾ��ջ��Ԫ�� 
    assert(top != NULL);   // "Stack is empty" ��ջ������ֹ���� 
    E it = top->element;
    Link<E>* ltemp = top->next;
    delete top;
    top = ltemp;
    size--;
    return it;
  }

  const E& topValue() const { // Return top value ����ջ��Ԫ�� 
    assert(top != 0);         // "Stack is empty" ��ջ������ֹ���� 
    return top->element;
  }

  int length() const { return size; } // Return length ����ջ���� 
};
