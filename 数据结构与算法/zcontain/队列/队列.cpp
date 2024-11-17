#include<stdio.h>
#include<stdlib.h>

//数据结构 = 结构定义 + 结构操作

//队列 先进先出 FIFO
//循环队列 解决假溢出问题

//定义顺序表
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

//队列结构定义
typedef struct Queue {
	Vector* data;
	int size; //容量
	int count; //元素个数
	int head; //队首
	int tail; //队尾
}Queue;

//初始化
Queue* initQueue(int n)
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	if (!q) return NULL;
	q->data = initVector(n);
	q->size = n;
	q->head = q->tail = q->count = 0;
	return q;
}

//销毁
void clearQueue(Queue* q)
{
	if (!q) return;
	clearVector(q->data);
	free(q);
}

//判空
int empty(Queue* q)
{
	return q->count == 0;
}

//入队
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

//出队
int pop(Queue* q)
{
	if (!q || empty(q)) return 0;
	q->head += 1;
	if (q->head == q->size)
		q->head = 0;
	q->count -= 1;
	return 1;
}

//访问队首元素
int front(Queue* q)
{
	return findVector(q->data, q->head);
}

int main()
{
	return 0;
}