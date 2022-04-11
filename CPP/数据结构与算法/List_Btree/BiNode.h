typedef char E;
class BiNode{
private:	
  E it;        	// The node's value
  BiNode* lc;  	// Pointer to left child
  BiNode* rc;  	// Pointer to right child
public:
  BiNode() { lc = rc = NULL; }
  BiNode(E e, BiNode* l,BiNode* r) { it = e; lc = l; rc = r; }
  E& element() { return it; }
  void setElement(E& e) { it = e; }
  //�������� 
  BiNode* left() { return lc; }
  void setLeft(BiNode* b) { lc = (BiNode*)b; }
  //�����Һ��� 
  BiNode* right() { return rc; }
  void setRight(BiNode* b) { rc = (BiNode*)b; }
  //�ж��Ƿ�ΪҶ�ӽڵ� 
  bool isLeaf() { return (lc == NULL) && (rc == NULL); }
};

