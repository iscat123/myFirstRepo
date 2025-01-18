#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
int rsl = 0;
bool isVal(int sum)
{
	for (int i = 2; i * i < sum; ++i)
	{
		if (sum % i == 0) return false;
	}
	return true;
}
void dfs(int i, int j, int n, int k, int sum)
{
	if (i > k) {
		if (isVal(sum))
			rsl += 1;
		return;
	}
	for (int m = j; m < n; ++m) {
		dfs(i + 1, m + 1, n, k, sum + arr[m]);
	}
}
int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		arr.push_back(x);
	}
	dfs(1, 0, n , k, 0);
	cout << rsl;
}