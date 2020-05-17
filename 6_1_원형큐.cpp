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
//	printf("메모리 에러");
//	exit(1);
//}
//
////초기화 함수
//void init(QueueType *q)
//{
//	q->front = 0;
//	q->rear = 0;
//}
//
////공백 상태 검출 함수
//int is_empty(QueueType *q)
//{
//	return (q->front == q->rear);
//}
//
////포화 상태 검출 함수
//int is_full(QueueType *q)
//{
//	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);	//큐가 다 꽉찬 상태인게 포화상태로 확인할려면 오류가 생긴다. 그러므로 한 개 를 더했을떄 0이면 포화상태인걸 확인한다.
//}
//
////삽입 함수
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
////삭제 함수
//element dequeue(QueueType *q)
//{
//	if (is_empty(q))
//		error();
//	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
//
//	return q->queue[q->front];
//}
//
////피크 함수
//element peek(QueueType *q)
//{
//	if (is_empty(q))
//		error();
//	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
//}
//
////주 함수
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