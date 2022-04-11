#include"BinNode.h"
#include"string"
#include<queue>
template<typename E>
class BinTree//��������
{
private:
	BinNode<E>*root;//�����
	void clear(BinNode<E>*r)//��ն�����
	{

		if (r == NULL)
			return;
		if (r->left() != NULL)
		{
			clear(r->left());
		}
		if (r->right() != NULL)
		{
			clear(r->right());
		}
		delete r;
		r = NULL;
	}
	void preOrder(BinNode<E>*tmp,void(*visit)(BinNode<E>*node))//���������void(*visit)(BinNode<E>*node)Ϊһ������ָ���������visit���洫�����ĺ������ڱ���������ʹ�ô������ĺ�������
	{
		if (tmp == NULL)
			return;
		visit(tmp);
		preOrder(tmp->left(),visit);
		preOrder(tmp->right(),visit);
	}
	void inOrder( BinNode<E>*tmp,void(*visit)(BinNode<E>*node))//���������void(*visit)(BinNode<E>*node)Ϊһ������ָ���������visit���洫�����ĺ������ڱ���������ʹ�ô������ĺ�������
	{
		if (tmp == NULL)
			return;
		inOrder(tmp->left(),visit);
		visit(tmp);
		inOrder(tmp->right(),visit);
	}
	void postOrder(BinNode<E>*tmp,void(*visit)(BinNode<E>*node))//���������void(*visit)(BinNode<E>*node)Ϊһ������ָ���������visit���洫�����ĺ������ڱ���������ʹ�ô������ĺ�������
	{
		if (tmp == NULL)
			return;
		postOrder(tmp->left(),visit);
		postOrder(tmp->right(),visit);
		visit(tmp);
	}
	void LevelOrderTranverse( BinNode<E>*tmp,void(*visit)(BinNode<E>*node))//��α�����void(*visit)(BinNode<E>*node)Ϊһ������ָ���������visit���洫�����ĺ������ڱ���������ʹ�ô������ĺ�������
	{
		if (tmp == NULL)
			return;
		queue<BinNode<E>*>que;
		que.push(tmp);
		BinNode<E>* curr;
		int sum = 0;
		while (que.empty() != true)
		{
			curr = que.front();
			if (curr->left() != NULL)
			{
				que.push(curr->left());
			}
			if (curr->right() != NULL)
			{
				que.push(curr->right());
			}
			que.pop();
			visit(curr);
		}
	}
	int BinTreeDepth(BinNode<E>*tmp)//��ö����������
	{
		if (tmp == NULL)
			return 0;
		int ld = 0;
		int rd = 0;
		if (tmp->left() != NULL)
			ld = BinTreeDepth(tmp->left());
		if (tmp->right() != NULL)
			rd = BinTreeDepth(tmp->right());
		if (ld >= rd)
			return ld + 1;
		else
			return rd + 1;
	}
	int BinTreeNodes(BinNode<E>*tmp)//��ö������Ľ����
	{
		if (tmp == NULL)
			return 0;
		queue<BinNode<E>*>que;
		que.push(tmp);
		BinNode<E>* curr;
		int sum = 0;
		while (que.empty() != true)
		{
			curr = que.front();
			if (curr->left() != NULL)
			{
				que.push(curr->left());
			}
			if (curr->right() != NULL)
			{
				que.push(curr->right());
			}
			que.pop();
			sum++;
		}
		return sum;
	}
	int BinTreeHeight(BinNode<E>*tmp)//��ö������ĸ߶�
	{
		if (tmp == NULL)
			return 0;
		return BinTreeDepth(tmp) - 1;
	}
	int BinTreeLeafs(BinNode<E>*tmp)//��ö�������Ҷ�ӽ����
	{
		if (tmp == NULL)
			return 0;
		queue<BinNode<E>*>que;
		que.push(tmp);
		BinNode<E>* curr;
		int sum = 0;
		while (que.empty() != true)
		{
			curr = que.front();
			if (curr->left() != NULL)
			{
				que.push(curr->left());
			}
			if (curr->right() != NULL)
			{
				que.push(curr->right());
			}
			if (curr->right() == NULL&&curr->left() == NULL)
				sum++;
			que.pop();
		}
		return sum;
	}
	bool find(BinNode<E>*tmp, E e)//���Ҷ��������Ƿ���ĳ����Ϊe�Ľ��
	{
		if (tmp == NULL)
			return false;
		queue<BinNode<E>*>que;
		que.push(tmp);
		BinNode<E>* curr;
		int sum = 0;
		while (que.empty() != true)
		{
			curr = que.front();
			if (curr->left() != NULL)
			{
				que.push(curr->left());
			}
			if (curr->right() != NULL)
			{
				que.push(curr->right());
			}
			if (curr->getValue() == e)
				return true;
			que.pop();
		}
		return false;
	}
public:
	BinTree()//Ĭ�Ϲ��캯��
	{
		root=new BinNode<E>;
	}
	~BinTree()//��������
	{
		clear(root);
	}
	bool BinTreeEmpty()//�ж϶������Ƿ�Ϊ��
	{
		if (root == NULL)
			return true;
		else
			return false;
	}
	BinNode<E>*getRoot()//��ø��ڵ�
	{
		return root;
	}
	void setRoot(BinNode<E>*r)//���ø��ڵ�
	{
		root = r;
	}
	//����ĺ����Ƕ���ĺ����������ڲ�������һЩͬ���ĺ��������ǲ����б�һ����ʵ�����ݵķ�װ���ⲿ�ĵ��ò����漰���ڲ������ݶ���
	void clear()//��ն�����
	{
		clear(root);
		root = NULL;
	}
	void preOrder(void(*visit)(BinNode<E>*node))//����������������Ӧ�ķ��ʺ������ɶԸõ�ǰ���ʵ�ֲ�ͬ���ܵķ��ʣ�������Ϊ�����
	{
		preOrder(root,visit);
	}
	void inOrder(void(*visit)(BinNode<E>*node)) //����������������Ӧ�ķ��ʺ������ɶԸõ�ǰ���ʵ�ֲ�ͬ���ܵķ��ʣ�������Ϊ�����
	{
		inOrder(root,visit);
	}
	void postOrder(void(*visit)(BinNode<E>*node))//����������������Ӧ�ķ��ʺ������ɶԸõ�ǰ���ʵ�ֲ�ͬ���ܵķ��ʣ�������Ϊ�����
	{
		postOrder(root,visit);
	}
	void LevelOrderTranverse(void(*visit)(BinNode<E>*node))//����������������Ӧ�ķ��ʺ������ɶԸõ�ǰ���ʵ�ֲ�ͬ���ܵķ��ʣ�������Ϊ�����
	{
		LevelOrderTranverse(root,visit);
	}
	int BinTreeDepth()//��ö��������
	{
		return BinTreeDepth(root);
	}
	int BinTreeNodes()//��ö����������
	{
		return BinTreeNodes(root);
	}
	int BinTreeHeight()//��ö������߶�
	{
		return BinTreeHeight(root);
	}
	int BinTreeLeafs()//��ö�����Ҷ�ӽ����
	{
		return BinTreeLeafs(root);
	}
	bool find(E e)//���Ҷ��������Ƿ������Ϊe�Ľ��
	{
		return find(root, e);
	}
};