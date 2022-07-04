#ifndef STACK
#define STACK
template <typename E> class Stack {
private:
  void operator =(const Stack&) {}     // Protect assignment
  Stack(const Stack&) {}         // Protect copy constructor

public:
  Stack() {}                       // Default constructor���캯��
  virtual ~Stack() {}              // Base destructor��������

  // Reinitialize the stack.  The user is responsible for
  // reclaiming the storage used by the stack elements.��ʼ��ջ ���û�������ձ�ʹ�����洢ջԪ�صĿռ�
  virtual void clear() = 0;

  // Push an element onto the top of the stack.
  // it: The element being pushed onto the stack.��ջ��ѹ�롰it��
  virtual void push(const E& it) = 0;

  // Remove the element at the top of the stack.
  // Return: The element at the top of the stack.ɾ��������ջ��Ԫ��
  virtual E pop() = 0;

  // Return: A copy of the top element.����ջ��Ԫ��
  virtual const E& topValue() const = 0;

  // Return: The number of elements in the stack.���ص�ǰջ�ĳ��� 
  virtual int length() const = 0;
};
#endif
