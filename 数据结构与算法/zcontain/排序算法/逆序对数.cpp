#include<vector>
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int func(vector<int>& arr)
{
	int size = arr.size();
	if (size<=1) return 0;
	int mid = size >> 1;
	vector<int> v1(arr.begin(), arr.begin() + mid) , v2(arr.begin()+mid,arr.end());
	int nl = func(v1);
	int nr = func(v2);
	int left = 0, right = 0, nmid = 0, all = 0;
	vector<int> merge(size);
	while (left<mid || right<size-mid)
	{
		if ((left >= mid) || ((right<size - mid) && (v1[left] > v2[right]))) {
			merge[all++] = v2[right];
			nmid+= mid-left;
			right++;
		}
		else if((right >= size-mid) || ((left <= mid) && (v1[left] <= v2[right]))) {
			merge[all++] = v1[left++];
		}
	}
	arr = merge;
	return nl + nr + nmid;
}

int main()
{
	srand(time(0));
	vector<int> arr(5);
	for (int i = 0; i < 5; ++i) {
		arr[i] = rand() % 100;
		cout << arr[i] << " ";
	}

	cout << endl << func(arr) << endl;
}