#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef int element;	//����� Ÿ��

typedef struct QueueNode
{
	element item;
	struct QueueNode *link;
}QueueNode;	//ť�� ����� Ÿ��

typedef struct //ť�� ADT ����(Abstract Data Type)
{
	QueueNode *front, *rear;
}QueueType;

//���� �Լ�
void error()
{
	printf("�޸� ���� ����");
	exit(1);
}

//�ʱ�ȭ �Լ�
void init(QueueType *q)
{
	q->front = NULL;
	q->rear = NULL;
}

//���� ���� ���� �Լ�
int is_empty(QueueType *q)
{
	return (q->front == NULL);
}

//���� �Լ�
void enqueue(QueueType *q, element item)
{
	QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
	if (temp == NULL)	error();
	else
	{
		temp->item = item;	//������ ����
		temp->link = NULL;	//��ũ �ʵ带 NULL�� ����
	
		if (is_empty(q))
		{
			q->front = temp;
			q->rear = temp;
		}
		else
		{	
			q->rear->link = temp;	//������ �߿�
			q->rear = temp;
		}
	}
}

//���� �Լ�
element dequeue(QueueType *q)
{
	QueueNode *temp = q->front;
	element
}

//peek �Լ� 
element peek(QueueType *q)
{
	if (is_empty(q))
		error();
	else
	{
		return q->front->item;	//������ ��ȯ
	}
}

//����� ť �׽�Ʈ �Լ�
int main(void)
{
	QueueType q;

	init(&q);

	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);

	printf("dequeue() = %d\n", dequeue(&q));
	printf("dequeue() = %d\n", dequeue(&q));
	printf("dequeue() = %d\n", dequeue(&q));

	return 0;
}