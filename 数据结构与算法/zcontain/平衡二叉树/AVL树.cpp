#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//AVL树
//数据结构 = 结构定义 + 结构操作

typedef struct Node {
	int key, height;
	Node* left, * right;
}Node;

Node* NIL;
void __nil()
{
	NIL = (Node*)malloc(sizeof(Node));
	NIL->key = -1;
	NIL->height = 0;
	NIL->left = NIL->right = NIL;
}

//初始化节点
Node* getNewNode(int key)
{
	Node* root = (Node*)malloc(sizeof(Node));
	root->key = key;
	root->height = 1;
	root->right = root->left = NIL;
	return root;
}

//清空
void clear(Node* root)
{
	if (root == NIL) return;
	clear(root->left);
	clear(root->right);
	free(root);
}


//计算树高
int getHeight(Node* root)
{
	return (root->left->height > root->right->height ? root->left->height : root->right->height) + 1;
}

//左旋
Node* left_rotate(Node* root)
{
	Node* newRoot = root->right;
	root->right = newRoot->left;
	newRoot->left = root;
	newRoot->left->height = getHeight(newRoot->left);
	newRoot->height = getHeight(newRoot);
	return newRoot;
}

//右旋
Node* right_rotate(Node* root)
{
	Node* newRoot = root->left;
	root->left = newRoot->right;
	newRoot->right = root;
	newRoot->right->height = getHeight(newRoot->right);
	newRoot->height = getHeight(newRoot);
	return newRoot;
}

//平衡调整
Node* blance(Node* root)
{
	if (abs(root->left->height - root->right->height) <= 1) return root;
	if (root->left->height > root->right->height)
	{
		if (root->left->left->height < root->left->right->height) {
			root->left = left_rotate(root->left);
		}
		root = right_rotate(root);
	}
	else
	{
		if (root->right->right->height < root->right->left->height){
			root->right = right_rotate(root->right);
		}
		root = left_rotate(root);
	}
	return root;
}

//插入
Node* insert(Node* root, int key)
{
	if (root == NIL) return getNewNode(key);
	if (root->key > key) root->left = insert(root->left, key);
	else if (root->key < key) root->right = insert(root->right, key);
	else return root;
	//重新计算树高
	root->height = getHeight(root);
	return blance(root);
}

//找左子树的最大值
int getLeftMax(Node* root)
{
	Node* node = root->left;
	while (node->right != NIL) node = node->right;
	return node->key;
}

//删除
Node* erase(Node* root, int key)
{
	if (root == NIL) return root;
	if (root->key > key) root->left = erase(root->left, key);
	else if (root->key < key) root->right = erase(root->right, key);
	else
	{
		if (root->left == NIL || root->left == NIL) {
			Node* temp = root->left != NIL ? root->left : root->right;
			free(root);
			return temp;
		}
		else
		{
			int max = getLeftMax(root);
			root->key = max;
			root->left = erase(root->left, max);
		}
	}
	//重新计算树高
	root->height = getHeight(root);
	return blance(root);
}

void preOrder(Node* root)
{
	if (root == NIL) return;
	printf("%d(%d,%d)\n", root->key, root->left->key, root->right->key);
	preOrder(root->left);
	preOrder(root->right);
}

int main()
{
	srand(time(0));
	__nil();
	Node* root = NIL;
	for (int i = 0; i < 10; i++)
	{
		int key = rand() % 100;
		printf("insert %d to avltree\n", key);
		root = insert(root, key);
		preOrder(root);
	}
	int key;
	while (~scanf_s("%d", &key))
	{
		printf("erase %d from avltree\n", key);
		root = erase(root, key);
		preOrder(root);
	}
	return 0;
}