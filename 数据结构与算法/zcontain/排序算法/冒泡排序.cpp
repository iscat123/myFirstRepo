#include"define.h"

//冒泡排序
//将数组分为“待排序区”和“已排序区”（“待排序区”在前半段，“已排序区”在后半段）
//每轮扫描“待排序区”，将当前元素与后一个元素比较大小，按排序要求判断是否交换位置
// 以上操作每一轮都会把”待排序区“中的最值移动到”待排序区“的最后一位，直到”待排序区“为空

void bubble_sort(vector<int>& arr)
{
	for (int i = arr.size()-1; i > 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

int main_bubbleSort()
{
	srand(time(0));
	vector<int> arr;
	for (int i = 0; i < MAX_N; ++i) arr.push_back(rand() % 100);
	output(arr);
	bubble_sort(arr);
	output(arr);
	return 0;
}