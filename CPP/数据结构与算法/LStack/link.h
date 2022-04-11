#include <iostream>
template <typename E> class Link {
public:
  E element;      // Value for this node 结点值 
  Link *next;      // Pointer to next node in list 结点指针：在链表中指向下一结点
  // Constructors 构造函数
  Link(const E& elemval, Link* nextval =NULL)
    { element = elemval;  next = nextval; }
  Link(Link* nextval =NULL) { next = nextval; }
};


