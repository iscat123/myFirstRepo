#include"define.h"
//ѡ������
//�������Ϊ�������������͡�����������
//ÿ�δӡ�������������ѡ��һ����ֵ���������������ĵ�һ��λ��

void selectSort(vector<int>& arr)
{
	int size = arr.size();
	for (int i = 0; i < size - 1; ++i)
	{
		int min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[min] > arr[j])
				min = j;
		}
		swap(arr[min], arr[i]);
	}
}

bool check(const vector<int>& arr)
{
	for (int i = 1; i < arr.size(); ++i)
	{
		if (arr[i] < arr[i - 1]) return false;
	}
	return true;
}

void output(const vector<int>& arr)
{
	for (int i = 0; i < arr.size(); ++i) cout << arr[i] << " ";
	cout << endl;
}

int main_select()
{
	srand(time(0));
	vector<int> arr;
	for (int i = 0; i < MAX_N; ++i) arr.push_back(rand() % 100);
	output(arr);
	selectSort(arr);
	output(arr);
	return 0;
}