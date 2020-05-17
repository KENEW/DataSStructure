#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int element;

typedef struct DlistNode	//노드의 타입
{
	element data;
	struct DlistNode *llink;
	struct DlistNode *rlink;
}dlistnode;

typedef struct DequeType	//덱의 타입
{
	DlistNode *head;
	DlistNode *tail;
}dequetype;

//오류 처리 함수
void error()
{
	printf("메모리 참조 에러");
	exit(1);
}

//초기화 함수
void init(dequetype *dq)
{
	dq->head = NULL;
	dq->tail = NULL;
}

//비어있는지 확인
int is_empty(dequetype *dq)
{
	return (dq->head == NULL);
}

dlistnode *create_node(dlistnode *llink, element item, dlistnode *rlink)
{
	dlistnode *node = (dlistnode *)malloc(sizeof(dlistnode));

	if (node == NULL) error();
	node->llink = llink;
	node->data = item;
	node->rlink = rlink;

	return node;
}
void add_rear(dequetype *dq, element item)
{
	dlistnode *new_node = create_node(dq->tail, item, NULL);

	if (is_empty(dq))
	{
		dq->head = new_node;
	}
	else
	{
		dq->tail = new_node;
		dq->tail->rlink = new_node;
	}

	dq->tail = new_node;
}

void add_front(dequetype *dq, element item)
{
	dlistnode *new_node = create_node(NULL, item, dq->head);

	if (is_empty(dq))
		dq->tail = new_node;

	else
	{
		dq->head->llink = new_node;
	}

	dq->head = new_node;
}

//전단에서의 삭제
element delete_front(dequetype *dq)
{
	element item;
	dlistnode *removed_node;

	if (is_empty(dq))
		error();
	else
	{
		removed_node = dq->head;		//삭제할 노드
		item = removed_node->data;		//데이터 추출
		dq->tail = dq->head->rlink;		//테일 포인터 변경

		free(removed_node);

		if (dq->head == NULL)			//공백 상태이면
			dq->tail = NULL;
		else
			dq->head->llink = NULL;
	}
	
	return item;
}

//후단에서의 삭제
element delete_rear(dequetype *dq)
{
	element item;
	dlistnode *removed_node;

	if (is_empty(dq)) error();
	else
	{
		removed_node = dq->tail;		//삭제할 노드
		item = removed_node->data;		//데이터 추출
		dq->tail = dq->tail->llink;		//테일 포인터 변경

		free(removed_node);				//메모리 공간 반납

		if (dq->tail == NULL)			//공백 상태이면
			dq->head = NULL;
		else
			dq->tail->rlink = NULL;
	}
	return item;
}

void display(dequetype *dq)
{
	dlistnode *p;
	
	printf("(");
	
	for (p = dq->head; p != NULL; p = p->rlink)
		printf("%d", p->data);

	printf(")\n");
}

int main(void)
{
	dequetype deque;

	init(&deque);

	add_front(&deque, 10);		//전단에 10 삽입
	add_front(&deque, 20);		//전단에 20 삽입
	add_rear(&deque, 30);		//후단에 30 삽입

	display(&deque);			//덱의 내용 출력

	delete_front(&deque);		//전단에서 삭제
	delete_rear(&deque);		//후단에서 삭제

	display(&deque);			//덱의 내용 출력
}