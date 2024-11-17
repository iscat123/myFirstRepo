#include<stdio.h>
#include<stdlib.h>

//���ݽṹ = �ṹ���� + �ṹ����

//���� �Ƚ��ȳ� FIFO
//ѭ������ ������������

//����˳���
typedef struct Vector{
	int* data;
	int size;
}Vector;

Vector* initVector(int n)
{
	Vector* v = (Vector*)malloc(sizeof(Vector));
	if (!v) return NULL;
	v->data = (int*)malloc(sizeof(int) * n);
	v->size = n;
	return v;
}

int insertVector(Vector* v, int pos, int val)
{
	if (!v) return 0;
	v->data[pos] = val;
	return 1;
}

void clearVector(Vector* v)
{
	if (!v) return;
	free(v->data);
	free(v);
}

int findVector(Vector* v, int pos)
{
	return v->data[pos];
}

//���нṹ����
typedef struct Queue {
	Vector* data;
	int size; //����
	int count; //Ԫ�ظ���
	int head; //����
	int tail; //��β
}Queue;

//��ʼ��
Queue* initQueue(int n)
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	if (!q) return NULL;
	q->data = initVector(n);
	q->size = n;
	q->head = q->tail = q->count = 0;
	return q;
}

//����
void clearQueue(Queue* q)
{
	if (!q) return;
	clearVector(q->data);
	free(q);
}

//�п�
int empty(Queue* q)
{
	return q->count == 0;
}

//���
int push(Queue* q, int val)
{
	if (q->count == q->size) return 0;
	if (insertVector(q->data, q->tail, val) == 0) return 0;
	q->count += 1;
	q->tail += 1;
	if (q->tail == q->size)
		q->tail = 0;
	return 1;
}

//����
int pop(Queue* q)
{
	if (!q || empty(q)) return 0;
	q->head += 1;
	if (q->head == q->size)
		q->head = 0;
	q->count -= 1;
	return 1;
}

//���ʶ���Ԫ��
int front(Queue* q)
{
	return findVector(q->data, q->head);
}

int main()
{
	return 0;
}