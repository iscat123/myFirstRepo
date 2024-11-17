#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 20
#define LEFT(i)  (i<<1)
#define RIGHT(i) ((i<<1) +1)
#define FATHER(i) (i>>1)
#define swap(a,b) { \
				int c = a; \
				a = b; \
				b = c; \
}

//向下调整
void downMeasure(int* arr, int index, int size)
{
	while (LEFT(index) <= size)
	{
		int max = index, l = LEFT(index), r = RIGHT(index);
		if (arr[index] < arr[l]) max = l;
		if (r<=size && arr[max] < arr[r]) max = r;
		if (max == index) break;
		swap(arr[max], arr[index]);
		index = max;
	}
}
//线性建堆法
void lineHeap(int* arr, int size)
{
	if (!arr || size <= 0) return;
	for (int i = size / 2; i >= 1; --i)
		downMeasure(arr, i, size);
}

//输出
void output(int* arr, int size)
{
	for (int i = 1; i <= size; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

int main_lineheap()
{
	srand(time(0));
	int* arr = (int*)malloc(sizeof(int) * MAX_N);
	for (int i = 0; i < MAX_N; ++i) arr[i] = rand() % 100;
	int* data = arr - 1;
	output(data, MAX_N);
	lineHeap(data, MAX_N);
	output(data, MAX_N);
	for (int i=MAX_N;i>=2;--i)
	{
		swap(data[i], data[1]);
		downMeasure(data, 1, i-1);
	}
	output(data, MAX_N);
	return 0;
}