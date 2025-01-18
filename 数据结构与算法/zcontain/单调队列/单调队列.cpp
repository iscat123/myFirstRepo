#include<iostream>
#include<vector>
#include<deque>
using namespace std;

//单调队列：维护区间最值

void outputarr(vector<int>& arr)
{
	printf("\n");
	int len = 0;
	for (int i = 0, I = arr.size(); i < I; i++)
	{
		len +=printf("%3d", i);
	}
	printf("\n");
	while (len--)printf("-");
	printf("\n");
	for (int i = 0, I = arr.size(); i < I; i++)
	{
		len += printf("%3d", arr[i]);
	}
	printf("\n");
}

int main()
{
	int m, n, k;
	cin >> m >> k;
	vector<int> arr;
	while (m--) {
		cin >> n;
		arr.push_back(n);
	}
	outputarr(arr);
	deque<int> q;
	for (int i = 0,I=arr.size(); i < I; ++i)
	{
		while (!q.empty() && arr[q.back()] > arr[i]) {
			q.pop_back();
		}
		q.push_back(i);
		if (q.front() == i - k) q.pop_front();
		printf("arr[%d,%d],%d\n", i - k + 1 > 0 ? i - k + 1 : 0, i, arr[q.front()]);
	}
	return 0;
}