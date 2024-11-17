#include<iostream>
#include<vector>
using namespace std;

int main_test02()
{
	int n;
	cin >> n;
	vector<string> opt(n), s;
	string target;
	for (int i = 0; i < n; i++) cin >> opt[i];
	cin >> target;
	bool flag = false;
	for (int i = 0; i < n; ++i)
	{
		if (opt[i] == target)
		{
			s.push_back(opt[i]);
			flag = true;
			break;
		}
		else if (opt[i] == string("return") && !s.empty())
			s.pop_back();
		else
			s.push_back(opt[i]);
	}
	if (flag)
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (i) cout << "->";
			cout << s[i];
		}
	}
	else
		cout << "not find";
	return 0;
}