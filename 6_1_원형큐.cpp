//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX_QUEUE_SIZE 100
//typedef int element;
//
//typedef struct
//{
//	element queue[MAX_QUEUE_SIZE];
//	int front, rear;
//}QueueType;
//
//void error()
//{
//	printf("�޸� ����");
//	exit(1);
//}
//
////�ʱ�ȭ �Լ�
//void init(QueueType *q)
//{
//	q->front = 0;
//	q->rear = 0;
//}
//
////���� ���� ���� �Լ�
//int is_empty(QueueType *q)
//{
//	return (q->front == q->rear);
//}
//
////��ȭ ���� ���� �Լ�
//int is_full(QueueType *q)
//{
//	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);	//ť�� �� ���� �����ΰ� ��ȭ���·� Ȯ���ҷ��� ������ �����. �׷��Ƿ� �� �� �� �������� 0�̸� ��ȭ�����ΰ� Ȯ���Ѵ�.
//}
//
////���� �Լ�
//void enqueue(QueueType *q, element item)
//{
//	if (is_full(q))
//	{
//		error();
//	}
//	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
//	q->queue[q->rear] = item;
//
//}
//
////���� �Լ�
//element dequeue(QueueType *q)
//{
//	if (is_empty(q))
//		error();
//	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
//
//	return q->queue[q->front];
//}
//
////��ũ �Լ�
//element peek(QueueType *q)
//{
//	if (is_empty(q))
//		error();
//	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
//}
//
////�� �Լ�
//int main(void)
//{
//	QueueType q;
//	init(&q);
//	printf("front = %d rear = %d\n", q.front, q.rear);
//
//	enqueue(&q, 1);
//	enqueue(&q, 2);
//	enqueue(&q, 3);
//
//	printf("dequeue() = %d\n", dequeue(&q));
//	printf("dequeue() = %d\n", dequeue(&q));
//	printf("dequeue() = %d\n", dequeue(&q));
//	printf("front = %d rear = %d\n", q.front, q.rear);
//
//	return 0;
//}