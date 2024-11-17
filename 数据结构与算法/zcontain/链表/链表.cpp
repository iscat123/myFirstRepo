#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DL 3
#define STR(n) #n
#define DIGIT_LEN_STR(n) "%" STR(n) "d"
//���ݽṹ = �ṹ���� + �ṹ����

//����
//�ṹ����
typedef struct Node {
	int data;
	Node* next;
}Node;

//�����ڵ�
Node* getNewNode(int val)
{
	Node* p = (Node*)malloc(sizeof(Node));
	if (!p) return NULL;
	p->data = val;
	p->next = NULL;
	return p;
}

//��������
void clear(Node* head)
{
	if (!head) return;
	for (Node* p = head; p; )
	{
		Node* q = p->next;
		free(p);
		p = q;
	}
}

//����
Node* insert(Node* head, int pos, int val)
{
	if (pos == 0)
	{
		Node* p = getNewNode(val);
		p->next = head;
		return p;
	}
	Node* p = head;
	for (int i = 1; i < pos; ++i) p = p->next;
	Node* q = getNewNode(val);
	q->next = p->next;
	p->next = q;
	return head;
}

//����ͷ�ڵ� ����
Node* virtual_insert(Node* head, int pos, int val)
{
	Node new_head, * p = &new_head, * node = getNewNode(val);
	p->next = head;
	for (int i = 0; i < pos; ++i) p = p->next;
	node->next = p->next;
	p->next = node;
	return new_head.next;
}

//�������
void output_linklist(Node* head)
{
	int len = 0;
	for (Node* p = head; p; p = p->next) len++;
	for (int i = 0; i < len; ++i)
	{
		printf(DIGIT_LEN_STR(DL), i);
		printf("  ");
	}
		
	printf("\n");
	for (Node* p = head; p; p = p->next)
		printf("%3d->", p->data);
	printf("\n");
}

//����
void find(Node* head, int val)
{
	if (!head) return;
	int pos = -1, n = 0;
	for (Node* p = head; p; p = p->next,n++)
	{
		if (p->data == val)
		{
			pos = n;
			break;
		}
	}
	if (pos == -1)
	{
		output_linklist(head);
		printf("û���ҵ�ֵ��%d\n",val);
	}
	else 
	{
		output_linklist(head);
		for (int i = 0; i < pos; ++i) printf("     ");
		printf("  ^\n");
		for (int i = 0; i < pos; ++i) printf("     ");
		printf("  |\n");
	}
}

//��ϰ��
//=========
//��ת����(�Լ��ķ���)
Node* reversalLinklist_my(Node* head)
{
	if (!head) return NULL;
	Node* p = head, * q = head->next;
	while (q)
	{
		Node* nextNode = q->next;
		q->next = p;
		p = q;
		q = nextNode;
	}
	head->next = NULL;
	return p;
}

//��ת����(�ǵݹ齲�ⷽ��:ͷ�巨)
Node* reversalLinklist(Node* head)
{
	Node new_head;
	new_head.next = NULL;
	for (Node* p = head; p;)
	{
		Node* q = p->next;
		p->next = new_head.next;
		new_head.next = p;
		p = q;
	}
	return new_head.next;
}

//��ת����(�ݹ�ʵ��)
Node* reversalLinklist_dg(Node* head)
{
	if (!head || !head->next) return head;
	Node* tail = head->next;
	Node* new_head = reversalLinklist_dg(head->next);
	head->next = tail->next;
	tail->next = head;
	return new_head;
}

//��������(����ָ��)
int hasCycleLinklist(Node* head)
{
	Node* p = head, * q = head;
	while (q && q->next)
	{
		q = q->next->next;
		p = p->next;
		if (p == q)
			return 1;
	}
	return 0;
}

//������(��������ָ�뷨)
int getNext(int n)
{
	int y = 0;
	while (n)
	{
		int d = n % 10;
		y += d * d;
		n /= 10;
	}
	return y;
}

int isHappy(int n)
{
	int p = n, q = n;
	while (q != 1)
	{
		p = getNext(p);
		q = getNext(getNext(q));
		if (p == q && q != 1)
			return 0;
	}
	return 1;
}

//��ת����
Node* rotateRight(Node* head , int n)
{
	if (!head) return head;
	int len = 0;
	for (Node* p = head; p; p = p->next) len += 1;
	n %= len;
	if (n == 0) return head;
	Node* p = head, * q = head, *tmp = head;
	for (int i = len; i >= 0; i--) p = p->next;
	while (p)
	{
		tmp = p;
		q = q->next;
		p = p->next;
	}
	tmp->next = head;
	head = q->next;
	q->next = NULL;
	return head;
}

//ɾ����������N���ڵ�(˫ָ��Ⱦ��ƶ���)
void removeNthFromEnd(Node* head, int n)
{
	if (!head) return;
	Node new_head;
	new_head.next = head;
	Node* p = &new_head, * q = &new_head;
	for (int i = 0; i <= n; ++i) p = p->next;
	while (p)
	{
		p = p->next;
		q = q->next;
	}
	p = q->next;
	q->next = p->next;
	free(p);
}

//���������
Node* cycleLinklist(Node* head)
{
	Node* p = head, * q = head;
	while (q && q->next)
	{
		p = p->next;
		q = q->next->next;
		if (p == q)
		{
			p = head;
			while (p != q)
			{
				p = p->next;
				q = q->next;
			}
			return p;
		}
	}
	return NULL;
}

//��ת�����
Node* reverseBetween_my(Node* head, int left, int right)
{
	if (!head || left >= right) return head;
	Node new_head,*preNode = &new_head,*endNode = &new_head;
	new_head.next = head;
	for (int i = 0; i < left - 1; ++i) preNode = preNode->next;
	for (int i = 0; i <= right; ++i) endNode = endNode->next;
	Node seversal_head, * p = preNode->next, * tail = p;
	seversal_head.next = NULL;
	for (int i = 0; i <= right - left; ++i)
	{
		Node* q = p->next;
		p->next = seversal_head.next;
		seversal_head.next = p;
		p = q;
	}
	preNode->next = seversal_head.next;
	tail->next = endNode;
	return new_head.next;
}

//��ת����(�ݹ�ʵ��)
Node* reverseBetween_dg(Node* head, int left, int right)
{
	if (left == 1 && right == 1) return head;
	if (left != 1)
	{
		head->next = reverseBetween_dg(head->next, left - 1, right - 1);
	}
	else
	{
		Node* tail = head->next;
		Node* new_head = reverseBetween_dg(head->next, left, right - 1);
		head->next = tail->next;
		tail->next = head;
		head = new_head;
	}
	return head;
}

void test_reverseBetween()
{
	Node* head = NULL;
	for (int i = 0; i < 8; ++i)
	{
		head = insert(head, 0, i);
	}
	output_linklist(head);
	head = reverseBetween_dg(head, 2, 5);
	output_linklist(head);
}

//��������
void main_op()
{
	srand(time(0));
	Node* head = NULL;
	const int MAX_OP = 8;
	for (int i = 0; i < MAX_OP; i++)
	{
		int pos = rand() % (i + 1), val = rand() % 100;
		printf("insert %d at %d to linklist\n", val, pos);
		head = virtual_insert(head, pos, val);
		output_linklist(head);

		find(head, val);
	}
	clear(head);
}

int main()
{
	test_reverseBetween();
	return 0;
}