#include <iostream>
using namespace std;
class BinTree:public BiNode{
private:
	char c;
	BiNode* root;          // Root of the BinTree BinTree���ĸ����
public:
	BiNode* Root(){
		return root;
	}
	void setroot(BiNode* n){
		root=n;
	}
	//�ж϶������Ƿ�Ϊ�� 
	bool BiTreeEmpty(BiNode* rt)
  {
    if(rt!=NULL) return true; 
    else return false;
  }
  //ǰ����� 
	void preorder(BiNode* rt)
  {
      if(rt!=NULL)
      {
          cout<<rt->element()<<" ";
          preorder(rt->left());
          preorder(rt->right());
      }
  }
  //������� 
  void Inorder(BiNode* rt)
  {
      if(rt!=NULL)
      {
          Inorder(rt->left());
	    cout<<rt->element()<<" ";
          Inorder(rt->right());
      }
  }
  //������� 
  void postorder(BiNode* rt)
  {
      if(rt!=NULL)
      {
          postorder(rt->left());
	    postorder(rt->right());
          cout<<rt->element()<<" ";
      }
  }
  //��α��� 
  void LevelOrderTraverse(BiNode* rt)
  {
      queue<BiNode*> q;
      if(rt!=NULL)
          q.push(rt);
      BiNode* b;
      while(!q.empty())
      {
          b=q.front();
          cout<<b->element()<<' ';
          q.pop();
          if(b->left())
              q.push(b->left());
          if(b->right())
              q.push(b->right());
      }
  }
  //��������� 
  int BiTreeDepth(BiNode* rt)
  {
    int lh=0,rh=0 ;
      if(rt!=NULL)
      {
          lh=BiTreeDepth(rt->left());
          rh=BiTreeDepth(rt->right());
          return (lh>rh?lh:rh)+1;
      }
      else  return 0 ;
  }
  //�ڵ���ͳ�� 
  int count(BiNode* rt)
  {
    if(rt)  return count(rt->left())+count(rt->right())+1;
      else return 0;
  }
};
