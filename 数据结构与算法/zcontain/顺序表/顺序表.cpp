#include <stdio.h>
#include <stdlib.h>

//数据结构 = 结构定义 + 结构操作

//顺序表
//结构定义
typedef struct vector {
	int size; //容量
	int count; //元素个数
	int* data; //缓存区
}vector;

//初始化顺序表
vector* getNewVector(int n)
{
	vector* p = (vector*)malloc(sizeof(vector));
	if (!p) return NULL;
	p->size = n;
	p->count = 0;
	p->data = (int*)malloc(sizeof(int) * n);
	return p;
}

//销毁顺序表
void clear(vector* v)
{
	if (!v) return;
	free(v->data);
	free(v);
}

//扩容操作
int expand(vector* v)
{
	if (!v) return 0;
	int size = v->size;
	int* p = (int*)realloc(v->data, sizeof(int) * size * 2); //realloc对指定内存重新分配空间
	if (!p) return 0;
	v->data = p;
	v->size = size * 2;
	return 1;
}

//插入操作
int insert(vector* v, int pos, int val)
{
	if (pos<0 || pos>v->count) return 0;
	if (v->size == v->count && !expand(v) ) return 0;
	for (int i = v->count - 1; i >= pos; --i)
	{
		v->data[i + 1] = v->data[i];
	}
	v->data[pos] = val;
	v->count++;
	return 1;
}

//删除操作
int erase(vector* v, int pos)
{
	if (pos < 0 || pos >= v->count) return 0;
	if (!v) return 0;
	for (int i = pos; i < v->count; i++)
	{
		v->data[i] = v->data[i + 1];
	}
	v->count--;
	return 1;
}


//主函数
int main()
{
	return 0;
}