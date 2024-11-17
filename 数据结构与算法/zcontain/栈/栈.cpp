#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//���ݽṹ = �ṹ���� + �ṹ����

//ջ �Ƚ���� FILO
//�ṹ����
typedef struct Stack {
	int* data;
	int top;
	int size;
}Stack;

//��ʼ��
Stack* initStack(int n)
{
	Stack* s = (Stack*)malloc(sizeof(Stack));
	if (!s) return NULL;
	s->data = (int*)malloc(sizeof(int) * n);
	s->size = n;
	s->top = -1;
	return s;
}

//����
void clearStack(Stack* s)
{
	if (!s) return;
	free(s->data);
	free(s);
}

//�п�
int empty(Stack* s)
{
	return s->top == -1;
}

//�鿴ջ��Ԫ��
int top(Stack* s)
{
	if (empty(s)) return 0;
	return s->data[s->top];
}

//��ջ
int push(Stack* s, int val)
{
	if (s->size == s->top + 1) return 0;
	s->data[s->top + 1] = val;
	s->top++;
	return 1;
}

//��ջ
int pop(Stack* s)
{
	if (empty(s)) return 0;
	s->top--;
	return 1;
}

void outputStack(Stack* s)
{
	printf("Stack :");
	for (int i = s->top; i >= 0; --i)
	{
		printf("%4d", s->data[i]);
	}
	printf("\n\n");
	return;
}

//����ƥ��
int fun(const char* str)
{
	Stack* s = initStack(20);
	while (str)
	{
		switch (*str)
		{
		case '(':
		case '[':
		case '{':
			push(s, *str);
			break;
		case ')':
		{
			if (top(s) == '(')
				pop(s);
			else
				return 0;
		}
		case ']':
		{
			if (top(s) == '[')
				pop(s);
			else
				return 0;
		}
		case '}':
		{
			if (top(s) == '{')
				pop(s);
			else
				return 0;
		}
		}
		str++;
	}
	if (empty(s))
		return 1;
	else
		return 0;
}

int main_test01()
{
	srand(time(0));
	Stack* s = initStack(5);
	for (int i = 0; i < 10; ++i)
	{
		int op = rand() % 3, val = rand() % 100;
		switch (op)
		{
		case 0:
			printf("pop stack, item = %d\n", top(s));
			pop(s);
			break;
		case 1:
		case 2:
			printf("push stack, item = %d\n", val);
			push(s, val);
			break;
		}
		outputStack(s);
	}
	clearStack(s);
	return 0;
}