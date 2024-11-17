#include <iostream>
using namespace std;

#define Red 1;
#define Black 2;
typedef int KEY_TYPE;

//���������ڵ�
typedef struct _zrbtree_node {
	unsigned char color;
	struct _zrbtree_node* left;
	struct _zrbtree_node* right;
	struct _zrbtree_node* parent;
	KEY_TYPE key;
	void* value;
}ZRbTreeNode;

//��������
typedef struct _zrbtree {
	ZRbTreeNode* root; //���ڵ�
	ZRbTreeNode* nil;  //�ⲿ�ڵ�
}ZRbTree;

//�����ڵ�
ZRbTreeNode* createNode(ZRbTree* tree, KEY_TYPE key)
{
	ZRbTreeNode* node = new ZRbTreeNode;
	node->color = Red;
	node->left = tree->nil;
	node->right = tree->nil;
	node->parent = tree->nil;
	node->key = key;
	node->value = NULL;
	return node;
}

//����
ZRbTreeNode* turnLeft(ZRbTree* tree, ZRbTreeNode* node)
{
	return NULL;
}

int main()
{
	return 0;
}