#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//����ʹ�ö����㷨��������������
// 1.������������������
// 2.֪x��y���ף�֪y��x�ѣ�֪�����±��׵�ֵ��ֵ֪���±��ѣ�
//�����ȼ������� �����Ķ��ְ�������˰ǰ����

#define MAX_N 10
//�����㷨
int binary_search(int* arr, int size, int n)
{
	int head = 0, tail = size - 1, mid = (head + tail) >> 1;
	while (head <= tail)
	{
		if (n == arr[mid]) return mid;
		else if (n > arr[mid]) head = mid + 1;
		else tail = mid - 1;
		mid = (head + tail) >> 1;
	}
	return -1;
}

void output(int* arr, int size)
{
	for (int i = 0; i < size; i++) printf("%d ", arr[i]);
	printf("\n");
}

int main_binarySearch()
{
	srand(time(0));
	int arr[MAX_N];
	arr[0] = rand() % 100;
	for (int i = 1; i < MAX_N; i++) arr[i] = arr[i-1] + rand() % 20;
	output(arr, MAX_N);
	int x;
	while (~scanf_s("%d", &x))
	{
		printf("index:%d\n", binary_search(arr, MAX_N, x));
	}
	return 0;
}