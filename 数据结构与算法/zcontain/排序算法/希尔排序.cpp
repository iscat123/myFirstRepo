#include"define.h"
//ϣ������ �������������
//���ò���step���������±���Ϊstep�ķ�Ϊһ��
//��ÿһ����в�������
//���ٲ���step�����飬��ÿ����в�������ֱ������Ϊ1

void shell_sort(vector<int>& arr)
{
	int size = arr.size(), step = size / 8;
	for (int step = size / 2; step > 0; step /= 2)
	{
		for (int i = 0; i < step; ++i)
		{
			//��������
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