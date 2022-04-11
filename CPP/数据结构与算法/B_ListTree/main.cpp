#include"BinTree.h"
template<typename E>
void printNode(BinNode<E>*tmp)//��ӡ����ֵ�ĺ���
{
	cout << tmp->getValue() << " ";
}
template<typename E>
BinNode<E>* creatBinaryTree(string s[], int &x,int n)//������������������������������������õݹ�˼�빹��
{
	if (s[x] =="/")
		return NULL;
	else
	{
		BinNode<E>*node = new BinNode<E>(s[x]);
		x = x + 1;
		if (x < n);
		node->setLeft(creatBinaryTree<E>(s, x,n));
		x = x + 1;
		if (x < n);
		node->setRight(creatBinaryTree<E>(s, x,n));
		return node;
	}
}	
 void creatBinaryTree(BinTree<string>*BT)//�����������ĺ���������������Ĺ������������������������������������м��һЩ������
{
	cout << "���ڽ��빹������������......" << endl;
	cout << "������������ж��ٸ����(�ս��Ҳ��������)" << endl;
	int n = 0;
	cin >> n;
	cout << "�밴preorder˳�����룬����NULL������'/',�ÿո�������߻س�����������" << endl;
	string*s = new string[n];
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	int now = 0;
	BT->setRoot(creatBinaryTree<string>(s, now, n));
}
int main()
{
	//������Ķ�������һ��ģ���࣬����ı�Ϊ������ͣ���������صĵط��ڡ�<>�����޸���ز���,������Ĭ��Ϊ������ձ��Ե�string
	BinTree<string>*BT = new BinTree<string>;
	creatBinaryTree(BT);
	//������Ѿ���������һ�ö�����
	//�����Ƕ������Ļ�������������չʾ
	cout << "there are some functions here" << endl;
	cout << "0:�ж��Ƿ�Ϊ������";
	if (BT->BinTreeEmpty() == true)
		cout << "��" << endl;
	else
		cout << "��" << endl;
	cout << "1:ǰ�����:";
	BT->preOrder(printNode);
	cout << endl;
	cout << "2:�������:";
	BT->inOrder(printNode);
	cout << endl;
	cout << "3:�������:";
	BT->postOrder(printNode);
	cout << endl;
	cout << "4:��α���:";
	BT->LevelOrderTranverse(printNode);
	cout << endl;
	cout << "5:��¼�������:";
	cout << BT->BinTreeDepth() << endl;
	cout << "6:��¼���ĸ߶�:";
	cout << BT->BinTreeHeight() << endl;
	cout << "7:ͳ�ƽ��:";
	cout << BT->BinTreeNodes() << endl;
	cout << "8:ͳ��Ҷ�ӽ��:";
	cout << BT->BinTreeLeafs() << endl;
	cout << "9:�ڶ������в���ĳ��ֵ�Ƿ���ڣ�Ĭ�ϲ��ҡ�C��:";
	if (BT->find("C") == true)
		cout << "����" << endl;
	else
		cout << "������" << endl;
	cout << "10:�Ƿ����:";
	BT->clear();
	cout << "�����" << endl;
	cout << "5:��¼�������:";
	cout << BT->BinTreeDepth() << endl;
	cout << "6:��¼���ĸ߶�:";
	cout << BT->BinTreeHeight() << endl;
	cout << "7:ͳ�ƽ��:";
	cout << BT->BinTreeNodes() << endl;
	cout << "8:ͳ��Ҷ�ӽ��:";
	cout << BT->BinTreeLeafs() << endl;
	system("pause");
}