#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef int element;
typedef struct StackNode
{
	element item;
	struct StackNode *link;
}stacknode;

typedef struct
{
	stacknode *top;
}linkedstacktype;

//초기화 함수
void init(linkedstacktype *s)
{
	s->top = NULL;
}

//공백 상태 검출 함수
int is_empty(linkedstacktype *s)
{
	return (s->top == NULL);
 }

//삽입 함수
void push(linkedstacktype *s, element item)
{
	stacknode *temp = (stacknode *)malloc(sizeof(StackNode));
	if (temp = NULL)
	{
		printf("메모리 할당 에러\n");
		return;
	}
	else
	{
		temp->item = item;
		temp->link = s->top;
		s->top = temp;
	}
}

//삭제 함수
element pop(linkedstacktype *s)
{
	if (is_empty(s))
	{
		printf("스택이 비어있음\n");
		exit(1);
	}
	else
	{
		stacknode *temp = s->top;
		element item = temp->item;

		s->top = s->top->link;	//그 자리의 배열을 놓치면 안되니깐 임시 구조체 변수를 만들어서 옮겨둔 다음에 메모리 헤체를 한다.
		free(temp);
		return item;
	}
}

//피크 함수
element peek(linkedstacktype *s)
{
	if (is_empty(s))
	{
		printf("스택이 비어있음\n");
		exit(1);
	}
	else
	{
		return s->top->item;
	}
}

//주 함수
int main(void)
{
	linkedstacktype s;
	init(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", is_empty(&s));
}