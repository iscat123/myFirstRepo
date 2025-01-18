#include<iostream>
using namespace std;
typedef struct AVLTree {
	int data;
	AVLTree* left;
	AVLTree* right;
	int height;
};

//创建一个新节点
AVLTree* createNode(const int& val) 
{
	AVLTree* newNode = new AVLTree();
	newNode->data = val;
	newNode->left = nullptr;
	newNode->right = nullptr;
	newNode->height = 1;
	return newNode;
} 

//重新计算树高
int getHeight(AVLTree* root)
{
	if (!root)
		return 0;
	int a = getHeight(root->left);
	int b = getHeight(root->right);
	return (a > b ? a : b) + 1;
}

//获取平衡因子
int getBalance(AVLTree* root)
{
	return getHeight(root->left) - getHeight(root->right);
}

//右旋函数
AVLTree* turnRight(AVLTree* root)
{
	//右旋：1.原来根节点的右子树成为新的根节点；
	//2.原来根节点成为新根节点的左子树，新根节点的原来左子树成为原来根节点的右子树；
	AVLTree* newRoot = root->right;
	AVLTree* temp = newRoot->left;
	newRoot->left = root;
	root->right = temp;
	root = newRoot;
	//重新计算树高
	root->height = getHeight(root);
	root->left->height = getHeight(root->left);
	return root;
}

//左旋函数
AVLTree* turnLeft(AVLTree* root)
{
	//左旋：1.原来根节点的左子树成为新的根节点；
	//2.原来的根节点成为新的根节点的右子树，新的根节点的原来的右子树成为原来根节点的左子树；
	AVLTree* newRoot = root->left;
	AVLTree* temp = newRoot->right;
	newRoot->right = root;
	root->left = temp;
	root = newRoot;
	//重新计算树高
	root->height = getHeight(root);
	root->right->height = getHeight(root->right);
	return root;
}

//插入元素
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
	//重新计算树高
	root->height = getHeight(root);
	//平衡因子
	int balance = getBalance(root);
	
	if (balance > 1 && getBalance(root->left) > 0) //LL失衡
		root = turnLeft(root);
	else if (balance > 1 && getBalance(root->left) < 0) //LR失衡
	{
		root->left = turnRight(root->left);
		root = turnLeft(root);
	}
	else if (balance < -1 && getBalance(root->right) < 0) //RR失衡
		root = turnRight(root);
	else if (balance <-1 && getBalance(root->right) > 0) //RL失衡
	{
		root->right = turnLeft(root->right);
		root = turnRight(root);
	}
	return root;
}

//查找元素
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
		cout << "find val:" << val << "用了" << count << "次" << endl;
	else
		cout << "can't find val:" << val << "即使用了" << count << "次" << endl;
	return root;
}

//删除元素
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
		//删除存在四种情况
		if (!root->right && !root->left) // 1.删除的节点是叶子，直接删除就行
		{
			delete root;
			root = nullptr;
		}
		else if (!root->left && root->right) // 2.删除的节点只有右子树，没有左子树，用右子树代替原来的节点
		{
			AVLTree* temp = root->right;
			delete root;
			root = temp;
		}
		else if (!root->right && root->left) // 3.删除的节点只有左子树，没有右子树，用左子树代替原来的节点
		{
			AVLTree* temp = root->left;
			delete root;
			root = temp;
		}
		else // 4.删除的节点同时有左右子树，两种方式：a.从左子树中找一个最大值，把这个值赋给该节点，然后去删除左子树中的最大值（左子树的最大值肯定没有右子树）。b.从右子树中找一个最小值，把这个值赋给该节点，然后去删除右子树中的最小值（右子树的最小值肯定没有左子树）。
		{
			//寻找右子树的最小值
			AVLTree* rightTree = root->right;
			while (rightTree->left)
			{
				rightTree = rightTree->left;
			}
			root->data = rightTree->data;
			root->right = deleteVal(root->right, root->data);
		}
	}
	//重新计算树高
	if (!root)
		return root;
	root->height = getHeight(root);
	//平衡因子
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

//先序遍历
void preOrder(AVLTree* root)
{
	if (!root)
		return;
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

//中序遍历
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

	cout << "先序遍历 ";
	preOrder(root);
	cout << endl;
	cout << "中序遍历 ";
	midOrder(root);
	cout << endl;


	root = deleteVal(root, 40);
	root = deleteVal(root, 50);
	cout << "先序遍历 ";
	preOrder(root);
	cout << endl;
	cout << "中序遍历 ";
	midOrder(root);
	cout << endl;
	return 0;
}





