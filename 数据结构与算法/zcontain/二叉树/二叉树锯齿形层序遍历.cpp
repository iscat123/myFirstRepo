#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct TreeNode {
	int key;
	TreeNode* left, *right;
}TreeNode;

vector<vector<int> > fun(TreeNode* root)
{
	if (!root) {};
	vector<vector<int>> rsl;
	queue<TreeNode*> q;
	q.push(root);
	int Index = 0;
	while (!q.empty())
	{
		int count = q.size();
		for (int i = 0; i < count; ++i)
		{
			TreeNode* node = q.front();
			q.pop();
			if (node->left) q.push(node->left);
			if (node->right) q.push(node->right);
			if (Index == rsl.size()) rsl.push_back(vector<int>());
			rsl[Index].push_back(node->key);
		}
		Index++;
	}
	/*for (int i = 0; i < rsl.size(); ++i)
	{
		if (i & 1)
		{
			vector<int>& temp = rsl[i];
			for (int j = 0, k = temp.size() - 1; j < k; j++, k--)
			{
				swap(temp[j], temp[k]);
			}
		}
	}*/
	for (int k = 1; k < rsl.size(); k += 2)
	{
		for (int i = 0, j = rsl[k].size() - 1; i < j; i++, j--)
			swap(rsl[k][i], rsl[k][j]);
	}
}