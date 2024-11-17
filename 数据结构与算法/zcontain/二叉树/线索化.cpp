#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//线索化是将二叉树的递归遍历，改成向链表式的遍历方式
typedef struct Node {
	int key;
	int ltag, rtag; //0:edge 1:thread
	Node* left, *right;
}Node;

Node* getNode(int key)
{
	Node* p = (Node*)malloc(sizeof(Node));
	if (!p) return NULL;
	p->key = key;
	p->ltag = 0;
	p->rtag = 0;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void clear(Node* root)
{
	if (!root) return;
	if (root->ltag == 0) clear(root->left);
	if (root->rtag == 0) clear(root->right);
	free(root);
}

Node* insert(Node* root, int key)
{
	if (!root)
	{
		root = getNode(key);
		return root;
	}
	if (rand() % 2)
		root->left = insert(root->left, key);
	else
		root->right = insert(root->right, key);
	return root;
}
Node* preNode = NULL, *preRoot = NULL;
void thread_tree(Node* root)
{
	if (!root) return;
	if (root->ltag == 0) thread_tree(root->left);
	if (!preRoot) preRoot = root;
	printf("%4d", root->key);
	if (!root->left)
	{
		root->left = preNode;
		root->ltag = 1;
	}
	if (preNode && !preNode->right)
	{
		preNode->right = root;
		preNode->rtag = 1;
	}
	preNode = root;
	if (root->rtag == 0) thread_tree(root->right);
}

void threadTree(Node* root)
{
	thread_tree(root);
	if (!preNode->right)
	{
		preNode->right = NULL;
		preNode->rtag = 1;
	}
}

Node* getNext(Node* root)
{
	if (root->rtag == 1) return root->right;
	root = root->right;
	while (root->ltag == 0)
	{
		root = root->left;
	}
	return root;
}

int main01()
{
	srand(time(0));
	Node* root=NULL;
	for (int i = 0; i < 10; ++i)
		root = insert(root, rand() % 100);
	threadTree(root);
	printf("\n");
	Node* p = preRoot;
	while (p)
	{
		printf("%4d", p->key);
		p = getNext(p);
	}
	return 0;
}