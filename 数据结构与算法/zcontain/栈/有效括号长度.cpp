#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};
class Solution {
public:
	int longestValidParentheses(string s) {
		int len = s.size();
		vector<int> match(len);
		for (int i = 0; i < len; i++) match[i] = 0;
		stack<int> sk;
		for (int i = 0; i < len; i++) 
		{
			if (s[i] == '(')
				sk.push(i);
			else
			{
				if (!sk.empty() && s[sk.top()] == '(')
				{
					match[sk.top()] = i;
					sk.pop();
				}
				else
					sk.push(i);
			}
		}
		int temp_ans=0, ans = 0, i=0;
		while(s[i])
		{
			if (match[i])
			{
				temp_ans += match[i] - i + 1;
				i = match[i] + 1;
			}
			else
			{
				i++;
				temp_ans = 0;
			}
			ans = ans > temp_ans ? ans : temp_ans;
		}
		return ans;
	}

	string simplifyPath(string path) {
		vector<string> s;
		string subPath, rsl;
		path += '/';
		int i = 0;
		while (path[i])
		{
			if (path[i] == '/')
			{
				if (subPath == "..")
				{
					if(!s.empty()) s.pop_back();
				}
				else if(subPath != "." && subPath !="") s.push_back(subPath);
				subPath.clear();
			}
			else
				subPath.push_back(path[i]);
			i++;
		}
		rsl = "/";
		for (int i = 0; i < s.size(); i++)
		{
			if(i)
				rsl += '/';
			rsl += s[i];
		}
		return rsl;
	}


	Node* copyRandomList(Node* head) {
		Node copy_head(0),*tail = &copy_head , *p = head;
		vector<Node*> vCopy,vOld,vRand;
		int i = 0;
		while (p)
		{
			Node* q = new Node(p->val);
			tail->next = q;
			tail = q;
			vCopy.push_back(q);
			vOld.push_back(p);
			vRand.push_back(p->random);
			i++;
			p = p->next;
		}
		p = copy_head.next, i = 0;
		while (p)
		{
			for (int k = 0; k < vOld.size(); ++k)
			{
				if (vOld[k] == vRand[i])
					p->random = vCopy[k];
			}
			p = p->next;
			i++;
		}
		return copy_head.next;
	}
};

int main_test02()
{
	Solution s;
	cout<<s.simplifyPath("/home/user/Documents/../Pictures");
	return 0;
}