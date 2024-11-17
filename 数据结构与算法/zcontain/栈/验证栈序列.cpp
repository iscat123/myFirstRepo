#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool isValid(const vector<int>& pushed, const vector<int>& poped)
{
	stack<int> s;
	int n = 0;
	for (int i = 0; i < poped.size(); ++i)
	{
		while (s.empty() || s.top() != poped[i])
		{
			if (n >= pushed.size())
				return false;
			s.push(pushed[n++]);
		}
		s.pop();
	}
	return true;
}

int main04()
{
	vector<int> pushed(5), poped(5);
	for (int i = 0; i < 5; ++i) cin >> pushed[i];
	for (int i = 0; i < 5; ++i) cin >> poped[i];
	if (isValid(pushed, poped))
		cout << "true";
	else
		cout << "false";
	return  0;

}