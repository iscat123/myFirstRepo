#include "define.h"
//��������
//������ֳɡ������������͡�����������
//���������������ĵ�һ��Ԫ�أ����뵽��������������

void insertSort(vector<int>& arr)
{
	int size = arr.size();
	for (int i = 1; i < size; ++i)
	{
		int j = i;
		while (j >= 1 && arr[j] < arr[j - 1])
		{
			swap(arr[j], arr[j - 1]);
			j--;
		}
	}
}

//�޼ල��������  �Բ���������Ż�
void unsupervision_insert_sort(vector<int>& arr)
{
	int min = 0;
	for (int i = 0; i < arr.size(); ++i) if (arr[min] > arr[i]) min = i;
	while (min)
	{
		swap(arr[min], arr[min - 1]);
		min--;
	}
	for (int i = 1; i < arr.size(); ++i)
	{
		int j = i;
		while (arr[j] < arr[j - 1])
		{
			swap(arr[j], arr[j - 1]);
			j--;
		}
	}
}

int main_insertSort()
{
	srand(time(0));
	vector<int> arr;
	for (int i = 0; i < MAX_N; ++i) arr.push_back(rand() % 100);
	output(arr);
	unsupervision_insert_sort(arr);
	output(arr);
	return 0;
}