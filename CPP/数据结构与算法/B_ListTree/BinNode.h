#include<iostream>
using namespace std;
template<typename E>
class BinNode//�����
{
private:
	BinNode*lc;//����
	BinNode*rc;//�Һ���
	E elem;
public:
	BinNode()//Ĭ�Ϲ��캯��
	{
		lc = NULL;
		rc = NULL;
	}
	BinNode(E tmp, BinNode*l=NULL, BinNode*r=NULL)//���ι��캯��
	{
		elem = tmp;
		lc = l;
		rc = r;
	}
	BinNode*left()//��������
	{
		return lc;
	}
	BinNode*right()//�����Һ���
	{
		return rc;
	}
	void setLeft(BinNode*l)//��������
	{
		lc = l;
	}
	void setRight(BinNode*r)//�����Һ���
	{
		rc = r;
	}
	void setValue(E tmp)//���õ�ǰ����ֵ
	{
		elem = tmp;
	}
	E getValue()//��õ�ǰ����ֵ
	{
		return elem;
	}
	bool isLeaf()//�жϵ�ǰ����Ƿ�ΪҶ�ӽ��
	{
		if (lc == NULL&&rc == NULL)
			return true;
		else
			return false;
	}
};