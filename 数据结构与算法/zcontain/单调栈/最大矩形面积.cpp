#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<cmath>
using namespace std;

int main()
{
	int x, n;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		cin >> x;
		arr.push_back(x);
	}
	stack<int> left, right;
	vector<pair<int, int> > lr;
	for (int i = 0; i < n; ++i) {
		lr.push_back({ -1,n-1 });
	}
	int rsl = 1;
	for (int i = 0; i < n; ++i) {
		while (!left.empty() && arr[left.top()] > arr[i]) {
			lr[left.top()].second = i - 1;
			left.pop();
		}
		left.push(i);
	}
	for (int i = n - 1; i >=0; --i) {
		while (!right.empty() && arr[right.top()] > arr[i]) {
			lr[right.top()].first = i;
			right.pop();
		}
		right.push(i);
	}
	for (int i = 0; i < n; ++i) {
		rsl = max(rsl, (lr[i].second - lr[i].first) * arr[i]);
	}
	cout << "最大矩形面积："<<rsl;
	return 0;
}