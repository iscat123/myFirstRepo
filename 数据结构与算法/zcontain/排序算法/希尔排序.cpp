#include"define.h"
//希尔排序 （分组插入排序）
//设置步长step，对数组下表间隔为step的分为一组
//对每一组进行插入排序
//减少步长step，分组，对每组进行插入排序，直到步长为1

void shell_sort(vector<int>& arr)
{
	int size = arr.size(), step = size / 8;
	for (int step = size / 2; step > 0; step /= 2)
	{
		for (int i = 0; i < step; ++i)
		{
			//插入排序
			for (int j = i+step; j < size; j += step)
			{
				int k = j;
				while (k >= step && arr[k] < arr[k - step])
				{
					swap(arr[k], arr[k - step]);
					k -= step;
				}
			}
		}
	}
}

int main_shellsort()
{
	srand(time(0));
	vector<int> arr;
	for (int i = 0; i < MAX_N; ++i) arr.push_back(rand() % 100);
	output(arr);
	shell_sort(arr);
	output(arr);
	return 0;
}