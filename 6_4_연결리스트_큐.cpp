#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef int element;	//요소의 타입

typedef struct QueueNode
{
	element item;
	struct QueueNode *link;
}QueueNode;	//큐의 노드의 타입

typedef struct //큐의 ADT 구현(Abstract Data Type)
{
	QueueNode *front, *rear;
}QueueType;

//오류 함수
void error()
{
	printf("메모리 참조 에러");
	exit(1);
}

//초기화 함수
void init(QueueType *q)
{
	q->front = NULL;
	q->rear = NULL;
}

//공백 상태 검출 함수
int is_empty(QueueType *q)
{
	return (q->front == NULL);
}

//삽입 함수
void enqueue(QueueType *q, element item)
{
	QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
	if (temp == NULL)	error();
	else
	{
		temp->item = item;	//데이터 저장
		temp->link = NULL;	//링크 필드를 NULL로 설정
	
		if (is_empty(q))
		{
			q->front = temp;
			q->rear = temp;
		}
		else
		{	
			q->rear->link = temp;	//순서가 중요
			q->rear = temp;
		}
	}
}

//삭제 함수
element dequeue(QueueType *q)
{
	QueueNode *temp = q->front;
	element
}

//peek 함수 
element peek(QueueType *q)
{
	if (is_empty(q))
		error();
	else
	{
		return q->front->item;	//데이터 변환
	}
}

//연결된 큐 테스트 함수
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