#include<iostream>
#include<vector>
#include<time.h>
#include<stack>
#include<unordered_set>
using namespace std;

//单调栈：维护元素最近大于或小于的值
#define MAX_N 10

void outputarr(vector<int>& arr)
{
	printf("\n");
	int len = 0;
	for (int i = 0, I = arr.size(); i < I; i++)
	{
		len += printf("%3d", i);
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

int main_tt()
{
	srand(time(0));
	vector<int> arr(MAX_N);
	unordered_set<int> hash;
	for (int i = 0; i < MAX_N; ++i)
	{
		int x = rand() % 10;
		while (hash.find(x) != hash.end()) {
			x = rand() % 10;
		}
		hash.insert(x);
		arr[i] = x;
	}
	outputarr(arr);
	stack<int> s;
	vector<int> right(MAX_N), left(MAX_N);
	for (int i = 0; i < MAX_N; ++i) {
		right[i] = i;
		left[i] = i;
	}
	//right
	for (int i = 0; i < MAX_N; ++i)
	{
		while (!s.empty() && arr[s.top()] > arr[i]) {
			right[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	//left
	while (!s.empty()) s.pop();
	for (int i = MAX_N - 1; i >=0 ; --i)
	{
		while (!s.empty() && arr[s.top()] > arr[i]) {
			left[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	for (int i = 0; i < MAX_N; ++i) {
		printf("arr[%d]:%d, l:arr[%d]:%d, r:arr[%d]:%d\n", i, arr[i], left[i], arr[left[i]], right[i], arr[right[i]]);
	}
	return 0;
}