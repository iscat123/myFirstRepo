#include<iostream>
using namespace std;
typedef struct AVLTree {
	int data;
	AVLTree* left;
	AVLTree* right;
	int height;
};

//����һ���½ڵ�
AVLTree* createNode(const int& val) 
{
	AVLTree* newNode = new AVLTree();
	newNode->data = val;
	newNode->left = nullptr;
	newNode->right = nullptr;
	newNode->height = 1;
	return newNode;
} 

//���¼�������
int getHeight(AVLTree* root)
{
	if (!root)
		return 0;
	int a = getHeight(root->left);
	int b = getHeight(root->right);
	return (a > b ? a : b) + 1;
}

//��ȡƽ������
int getBalance(AVLTree* root)
{
	return getHeight(root->left) - getHeight(root->right);
}

//��������
AVLTree* turnRight(AVLTree* root)
{
	//������1.ԭ�����ڵ����������Ϊ�µĸ��ڵ㣻
	//2.ԭ�����ڵ��Ϊ�¸��ڵ�����������¸��ڵ��ԭ����������Ϊԭ�����ڵ����������
	AVLTree* newRoot = root->right;
	AVLTree* temp = newRoot->left;
	newRoot->left = root;
	root->right = temp;
	root = newRoot;
	//���¼�������
	root->height = getHeight(root);
	root->left->height = getHeight(root->left);
	return root;
}

//��������
AVLTree* turnLeft(AVLTree* root)
{
	//������1.ԭ�����ڵ����������Ϊ�µĸ��ڵ㣻
	//2.ԭ���ĸ��ڵ��Ϊ�µĸ��ڵ�����������µĸ��ڵ��ԭ������������Ϊԭ�����ڵ����������
	AVLTree* newRoot = root->left;
	AVLTree* temp = newRoot->right;
	newRoot->right = root;
	root->left = temp;
	root = newRoot;
	//���¼�������
	root->height = getHeight(root);
	root->right->height = getHeight(root->right);
	return root;
}

//����Ԫ��
AVLTree* insert(AVLTree* root, const int& val)
{
	if (!root)
	{
		root = createNode(val);
		return root;
	}
	if (root->data < val)
		root->right = insert(root->right, val);
	else if (root->data > val)
		root->left = insert(root->left, val);
	else
		return root;
	//���¼�������
	root->height = getHeight(root);
	//ƽ������
	int balance = getBalance(root);
	
	if (balance > 1 && getBalance(root->left) > 0) //LLʧ��
		root = turnLeft(root);
	else if (balance > 1 && getBalance(root->left) < 0) //LRʧ��
	{
		root->left = turnRight(root->left);
		root = turnLeft(root);
	}
	else if (balance < -1 && getBalance(root->right) < 0) //RRʧ��
		root = turnRight(root);
	else if (balance <-1 && getBalance(root->right) > 0) //RLʧ��
	{
		root->right = turnLeft(root->right);
		root = turnRight(root);
	}
	return root;
}

//����Ԫ��
AVLTree* find(AVLTree* root, const int& val)
{
	if (!root)
		return root;
	int count = 0;
	while (root)
	{
		++count;
		if (root->data == val)
			break;
		else if (root->data > val)
			root = root->left;
		else
			root = root->right;
	}
	if (root)
		cout << "find val:" << val << "����" << count << "��" << endl;
	else
		cout << "can't find val:" << val << "��ʹ����" << count << "��" << endl;
	return root;
}

//ɾ��Ԫ��
AVLTree* deleteVal(AVLTree* root, const int& val)
{
	if (!root)
		return root;
	if (root->data > val)
		root->left = deleteVal(root->left, val);
	else if (root->data < val)
		root->right = deleteVal(root->right, val);
	else
	{
		//ɾ�������������
		if (!root->right && !root->left) // 1.ɾ���Ľڵ���Ҷ�ӣ�ֱ��ɾ������
		{
			delete root;
			root = nullptr;
		}
		else if (!root->left && root->right) // 2.ɾ���Ľڵ�ֻ����������û����������������������ԭ���Ľڵ�
		{
			AVLTree* temp = root->right;
			delete root;
			root = temp;
		}
		else if (!root->right && root->left) // 3.ɾ���Ľڵ�ֻ����������û����������������������ԭ���Ľڵ�
		{
			AVLTree* temp = root->left;
			delete root;
			root = temp;
		}
		else // 4.ɾ���Ľڵ�ͬʱ���������������ַ�ʽ��a.������������һ�����ֵ�������ֵ�����ýڵ㣬Ȼ��ȥɾ���������е����ֵ�������������ֵ�϶�û������������b.������������һ����Сֵ�������ֵ�����ýڵ㣬Ȼ��ȥɾ���������е���Сֵ������������Сֵ�϶�û������������
		{
			//Ѱ������������Сֵ
			AVLTree* rightTree = root->right;
			while (rightTree->left)
			{
				rightTree = rightTree->left;
			}
			root->data = rightTree->data;
			root->right = deleteVal(root->right, root->data);
		}
	}
	//���¼�������
	if (!root)
		return root;
	root->height = getHeight(root);
	//ƽ������
	int balance = getBalance(root);
	if (balance > 1 && getBalance(root->left) >= 0)
		root = turnLeft(root);
	else if (balance > 1 && getBalance(root->left) < 0)
	{
		root->left = turnRight(root->left);
		root = turnLeft(root);
	}
	else if (balance < -1 && getBalance(root->right) <= 0)
		root = turnRight(root);
	else if (balance < -1 && getBalance(root->right)>0)
	{
		root->right = turnLeft(root->right);
		root = turnRight(root);
	}
	return root;
}

//�������
void preOrder(AVLTree* root)
{
	if (!root)
		return;
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

//�������
void midOrder(AVLTree* root)
{
	if (!root)
		return;
	midOrder(root->left);
	cout << root->data << " ";
	midOrder(root->right);
}

int main_a()
{
	AVLTree* root =nullptr;	
	root = insert(root, 90);
	root = insert(root, 10);
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 50);
	root = insert(root, 40);
	root = insert(root, 80);
	root = insert(root, 60);
	root = insert(root, 70);
	find(root, 80);

	cout << "������� ";
	preOrder(root);
	cout << endl;
	cout << "������� ";
	midOrder(root);
	cout << endl;


	root = deleteVal(root, 40);
	root = deleteVal(root, 50);
	cout << "������� ";
	preOrder(root);
	cout << endl;
	cout << "������� ";
	midOrder(root);
	cout << endl;
	return 0;
}





