#include"define.h"

//ð������
//�������Ϊ�������������͡���������������������������ǰ��Σ��������������ں��Σ�
//ÿ��ɨ�衰����������������ǰԪ�����һ��Ԫ�رȽϴ�С��������Ҫ���ж��Ƿ񽻻�λ��
// ���ϲ���ÿһ�ֶ���ѡ������������е���ֵ�ƶ��������������������һλ��ֱ��������������Ϊ��

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