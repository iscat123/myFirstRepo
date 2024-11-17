#include <stdio.h>
#include <stdlib.h>

//�� ���ȶ���
//���ݽṹ = �ṹ���� + �ṹ����
//��Ҫ���ʣ���ά�����Ǽ��ϵ�������Сֵ

#define ROOT 1
#define FATHER(i) (i/2)
#define LEFT(i) (2*i)
#define RIGHT(i) (2*i+1)

typedef struct PriorityQueue {
	int* data, * __data; //data�������±�ƫ�� �ø��ڵ��Ӧ�����е�����Ϊ1 ������ 2*i ������2*i+1
	int size, n;
}PriorityQueue;

//��ʼ��
PriorityQueue* initPQ(int size)
{
	PriorityQueue* q = (PriorityQueue*)malloc(sizeof(PriorityQueue));
	if (!q) return NULL;
	q->__data = (int*)malloc(sizeof(int) * size);
	q->data = q->__data - 1;
	q->size = size;
	q->n = 0;
	return q;
}

//���
void clear(PriorityQueue* q)
{
	if (!q) return;
	free(q->__data);
	free(q);
	return;
}

//�п�
int empty(PriorityQueue* q)
{
	return q->n == 0;
}

//����
int full(PriorityQueue* q)
{
	return q->n == q->size;
}

//��ͷԪ��
int front(PriorityQueue* q)
{
	return q->data[ROOT];
}

void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

//���ϵ���
void upMeasure(PriorityQueue* q, int index)
{
	while (index > ROOT && q->data[index] > q->data[FATHER(index)])
	{
		swap(&q->data[index], &q->data[FATHER(index)]);
		index = FATHER(index);
	}
	return;
}

//���µ���
void downMeasure(PriorityQueue* q, int index)
{
	while (LEFT(index) < q->n)
	{
		int max = index, l = LEFT(index), r = RIGHT(index);
		if (q->data[index] < q->data[l]) max = l;
		if (q->data[max] < q->data[r]) max = r;
		if (index == max) break;
		swap(&q->data[index], &q->data[max]);
	}
	return;
}

//���
int push(PriorityQueue* q, int val)
{
	if (full(q)) return 0;
	q->n += 1;
	q->data[q->n] = val;
	upMeasure(q, q->n);
	return 1;
}

//����
int pop(PriorityQueue* q)
{
	if (empty(q)) return 0;
	q->data[ROOT] = q->data[q->n];
	q->n -= 1;
	downMeasure(q, ROOT);
	return 1;
}

//���
void output(PriorityQueue* q)
{
	printf("PQ(%d)\n",q->n);
	for (int i = 1; i <= q->n; ++i)
	{
		printf("%d ", q->data[i]);
	}
	printf("\n");
}
int main01()
{
	PriorityQueue* q = initPQ(100);
	int op = 0;
	while (~scanf_s("%d", &op))
	{
		if (op == 1)
		{
			int val = 0;
			scanf_s("%d", &val);
			printf("push %d to priority queue\n", val);
			push(q, val);
			output(q);
		}
		else
		{
			printf("pop %d from priority queue\n", front(q));
			pop(q);
			output(q);
		}
	}
	clear(q);
	return 0;
}