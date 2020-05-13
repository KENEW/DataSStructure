//#include<stdio.h>
//#include<stdlib.h>
//
//#define MAX_STACK_SIZE 100
//typedef int element;
//typedef struct
//{
//	element stack[MAX_STACK_SIZE];
//	int top;
//}StackType;
//
////스택 초기화 함수
//void init(StackType *s)
//{
//	s->top = -1;
//}
//
////공백 상태 검출 함수
//int is_empty(StackType *s)
//{
//	return (s->top == -1);
//}
//
////포화 상태 검출 함수
//int is_full(StackType *s)
//{
//	return (s->top == MAX_STACK_SIZE - 1);
//}
//
////삽입 함수
//void push(StackType *s, element item)
//{
//	if (is_full(s))
//	{
//		printf("메모리 참조 에러");
//		return;
//	}
//	else s->stack[++(s->top)] = item;
//}
//
////삭제 함수
//element pop(StackType *s)
//{
//	if (is_empty(s))
//	{
//		printf("메모리 참조 에러");
//		exit(1);
//	}
//	else return s->stack[(s->top)--];
//}
//
////피크 함수
//element peek(StackType *s)
//{
//	if (is_empty(s))
//	{
//		printf("메모리 참조 에러");
//		exit(1);
//	}
//	else return s->stack[s->top];
//}
//
////주 함수
//int main(void)
//{
//	StackType s;
//
//	init(&s);
//	push(&s, 1);
//	push(&s, 2);
//	push(&s, 3);
//	printf("%d\n", pop(&s));
//	printf("%d\n", pop(&s));
//	printf("%d\n", pop(&s));
//	printf("%d\n", is_empty(&s));
//}