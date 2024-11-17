#include"define.h"

//�鲢����
//������ֳ������֣����Σ�
//�ظ����������ֱ��ÿ������ֻ��������Ԫ�أ�����ÿ��������
//�鲢�����������ֺϲ���ֱ��ȫ���ϲ�

void merge_sort(vector<int>& arr)
{
	int size = arr.size();
	if (size <= 1) return;
	/*if (size == 3)
	{
		if (arr[0] > arr[1]) { 
			swap(arr[0], arr[1]); 
		}
		if (arr[2] < arr[0]) {
			swap(arr[2], arr[0]);
			swap(arr[2], arr[1]);
		}
		else if (arr[2] < arr[1]) {
			swap(arr[1], arr[2]);
		}
		return;
	}
	if (size == 2)
	{
		if (arr[0] > arr[1]) {
			swap(arr[0], arr[1]);
		}
		return;
	}*/
	vector<int> v1(arr.begin(),arr.begin()+size/2), v2(arr.begin()+size/2,arr.end());
	merge_sort(v1);
	merge_sort(v2);
	int i = 0, j = 0, k = 0;
	while(i < size / 2 && j < size - size / 2)
	{
		if (v1[i] <= v2[j]) arr[k] = v1[i++];
		else arr[k] = v2[j++];
		k++;
	}
	while (i < size / 2) {
		arr[k++] = v1[i++];
	}
	while (j < size - size / 2) {
		arr[k++] = v2[j++];
	}
}
int main_mergeSort()
{
	srand(time(0));
	vector<int> arr;
	for (int i = 0; i < MAX_N; ++i) arr.push_back(rand() % 100);
	output(arr);
	int start = clock();
	merge_sort(arr);
	int end = clock();
	printf("\n\n%d ms\n\n", (end - start) * 1000 / CLOCKS_PER_SEC);
	output(arr);
	if (!check(arr)) printf("\n false;;; \n");
	return 0;
}