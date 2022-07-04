#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
class ABinTree:public ANode{
private:
	int root;          	// Root of the BinTree BinTree���ĸ����
public:
	vector<ANode> nodeArray; 	//������洢�ڵ� 
	int Root(){
		return 0;
	}
	void setroot(int n){
		root=n;
	}
	//�Ƿ�Ϊ���� 
	bool BiTreeEmpty(int rt)
    {
	    if(nodeArray[rt].element()=='#') 
			return true; //��һ�ÿ��� 
	    else 
			return false;//���ǿ��� 
    }

	//ǰ����� 
	void preorder(int rt)
    {
    	if(nodeArray[rt].element()=='#')
    		return;
    	else
        {
            cout<<nodeArray[rt].element()<<" ";
            preorder(nodeArray[rt].left());
            preorder(nodeArray[rt].right());
        }
    }
	//������� 
  void Inorder(int rt)
  {
      if(nodeArray[rt].element()!='#')
      {
          Inorder(nodeArray[rt].left());
	    cout<<nodeArray[rt].element()<<" ";
          Inorder(nodeArray[rt].right());
      }
  }
	//������� 
    void postorder(int rt)
    {
        if(nodeArray[rt].element()!='#')
        {
            postorder(nodeArray[rt].left());
		    postorder(nodeArray[rt].right());
            cout<<nodeArray[rt].element()<<" ";
        }
    }
	//��α��� 
    void LevelOrderTraverse(int rt)
    {
        queue<int> q;
        if(nodeArray[rt].element()!='#')
            q.push(rt);
        int temp;
        while(!q.empty())
        {
            temp=q.front();
            cout<<nodeArray[temp].element()<<' ';
            q.pop();
            int l=nodeArray[temp].left();
            int r=nodeArray[temp].right();
            if(nodeArray[l].element()!='#')
                q.push(l);
            if(nodeArray[r].element()!='#')
                q.push(r);
        }
    }
	//������� 
    int BiTreeDepth(int rt)
    {
	    int lh=0,rh=0 ;
        if(nodeArray[rt].element()!='#')
        {
            lh=BiTreeDepth(nodeArray[rt].left());
            rh=BiTreeDepth(nodeArray[rt].right());
            return (lh>rh?lh:rh)+1;
        }
        else  return 0 ;
    }
	//������ 
    int count(int rt)
    {
	    if(nodeArray[rt].element()!='#')  return count(nodeArray[rt].left())+count(nodeArray[rt].right())+1;
        else return 0;
    }
};

