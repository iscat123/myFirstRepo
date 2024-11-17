#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//A(B,C)
#define KEY(n) (n? n->key:-1)
typedef struct TreeNode {
	int key;
	TreeNode* left, *right;
}TreeNode;

TreeNode* getTreeNode(int key)
{
	TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
	if (!p) return NULL;
	p->key = key;
	p->right = p->left = NULL;
	return p;
}

void clear(TreeNode* root)
{
	if (!root) return;
	clear(root->left);
	clear(root->right);
	free(root);
}

TreeNode* insert(TreeNode* root, int key)
{
	if (!root) return getTreeNode(key);
	if (rand() % 2) root->left = insert(root->left, key);
	else root->right = insert(root->right, key);
	return root;
}

void serialize(TreeNode* root, char* str,int* len)
{
	if (!root) return;
	*len += snprintf(str + *len,100, "%d", root->key);
	if (!root->left && !root->right) return;
	*len += snprintf(str + *len, 100, "(");
	serialize(root->left, str, len);
	if (root->right)
	{
		*len += snprintf(str + *len, 100, ",");
		serialize(root->right, str, len);
	}
	*len += snprintf(str + *len, 100, ")");
}

TreeNode* deSerialize(char* str, int len)
{
	TreeNode* s[20];
	int top = -1;
	TreeNode* node = NULL, *root = NULL;
	int leftOrRight = 0; //0代表左子树，1代表右子树
	int scode = 0;
	for (int i = 0; i < len; ++i)
	{
		if (str[i] >= '0' && str[i] <= '9')
			scode = 0;
		else if (str[i] == '(')
			scode = 1;
		else if (str[i] == ',')
			scode = 2;
		else if (str[i] == ')')
			scode = 3;
		else
			scode = 4;
		switch (scode)
		{
		case 0:
		{
			int num = 0;
			while (str[i] >= '0' && str[i] <= '9')
				num = num * 10 + (str[i++] - '0');
			node = getTreeNode(num);
			if (top != -1)
			{
				if (leftOrRight)
					s[top]->right = node;
				else
					s[top]->left = node;
			}
			i -= 1;
			break;
		}
		case 1:
		{
			s[++top] = node;
			leftOrRight = 0;
			break;
		}
		case 2:
		{
			leftOrRight = 1;
			break;
		}
		case 3:
		{
			root = s[top];
			top -= 1;
			break;
		}
		}
	}
	return root;
}

void print(TreeNode* root)
{
	printf("%d(%d,%d)\n", KEY(root), KEY(root->left), KEY(root->right));
}
void preOrd(TreeNode* root)
{
	if (!root) return;
	print(root);
	preOrd(root->left);
	preOrd(root->right);
}

int main02()
{
	srand((unsigned int)time(0));
	TreeNode* root = NULL;
	char str[100];
	int len = 0;
	for (int i = 0; i < 10; ++i)
	{
		root = insert(root, rand() % 100);
	}
	preOrd(root);
	printf("\n\n");
	serialize(root, str, &len);
	printf("%s", str);
	printf("\n\n");
	root = deSerialize(str, len);
	preOrd(root);
	return 0;
}