#include"define.h"

//��������
//��������Ԫ����Ϊ��׼�������������з������õ���������
//Ȼ��Եõ���������������������Դ����ƣ�ֱ����ָ����ڵ�����ָ��

void quick_sort(vector<int>& arr, int left, int right)
{
	if (left >= right) return;
	int base = arr[left], l = left, r = right;
	while (r > l)
	{
		while (r > l && arr[r] >= base) r--;
		if (r > l) arr[l++] = arr[r];
		while (r > l && arr[l] <= base) l++;
		if (r > l) arr[r--] = arr[l];
	}
	arr[l] = base;
	quick_sort(arr, left, l - 1);
	quick_sort(arr, l + 1, right);
}

int main_quickSort()
{
	srand(time(0));
	vector<int> arr;
	for (int i = 0; i < MAX_N; ++i) arr.push_back(rand() % 100);
	output(arr);
	int start = clock();
	quick_sort(arr,0,MAX_N-1);
	int end = clock();
	printf("\n\n%d ms\n\n", (end - start) * 1000 / CLOCKS_PER_SEC);
	output(arr);
	return 0;
}