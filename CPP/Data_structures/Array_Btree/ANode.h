typedef char E;
class ANode{
private:
		E it;
		int lc;// Index of left child
		int rc;// Index of right child
		int p;
public:
  	ANode() { lc = rc = 0; }
  	//���ؽڵ�Ԫ�� 
  	E element() { return it; }
  	//���ýڵ�Ԫ�� 
  	void setElement(E e) { it = e; }
  	//���������±� 
  	int left() { return lc; }
  	//�������� 
  	void setLeft(int i) { lc = 2*i+1; }
  	//�����ҽڵ��±� 
  	int right() { return rc; }
  	//�����Һ��� 
  	void setRight(int i) { rc = 2*i+2; }
};

