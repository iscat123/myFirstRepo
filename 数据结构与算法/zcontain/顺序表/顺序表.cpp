#include <stdio.h>
#include <stdlib.h>

//���ݽṹ = �ṹ���� + �ṹ����

//˳���
//�ṹ����
typedef struct vector {
	int size; //����
	int count; //Ԫ�ظ���
	int* data; //������
}vector;

//��ʼ��˳���
vector* getNewVector(int n)
{
	vector* p = (vector*)malloc(sizeof(vector));
	if (!p) return NULL;
	p->size = n;
	p->count = 0;
	p->data = (int*)malloc(sizeof(int) * n);
	return p;
}

//����˳���
void clear(vector* v)
{
	if (!v) return;
	free(v->data);
	free(v);
}

//���ݲ���
int expand(vector* v)
{
	if (!v) return 0;
	int size = v->size;
	int* p = (int*)realloc(v->data, sizeof(int) * size * 2); //realloc��ָ���ڴ����·���ռ�
	if (!p) return 0;
	v->data = p;
	v->size = size * 2;
	return 1;
}

//�������
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

//ɾ������
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


//������
int main()
{
	return 0;
}