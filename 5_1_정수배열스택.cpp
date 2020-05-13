//#include<stdio.h>
//#include<stdlib.h>
//
//#define MAX_STACK_SIZE 100
//typedef int element;
//element stack[MAX_STACK_SIZE];
//int top = -1;
//
////공백 상태 검출 상태
//int is_empty()
//{
//	return (top == -1);
//}
//
////포화 상태 검출 함수
//int is_full()
//{
//	return (top == MAX_STACK_SIZE - 1);
//}
//
////삽입 함수
//void push(element item)
//{
//	if (is_full())
//	{
//		printf("메모리 참조 에러");
//		return;
//	}
//	else
//		stack[top++] = item;
//}
//
////삭제 함수
//element pop()
//{
//	if (is_empty())
//	{
//		printf("메모리 참조 에러");
//		exit(1);
//	}
//	else return stack[top--];
//}
//
////주 함수
//void main()
//{
//	push(1);
//	push(2);
//	push(3);
//	
//	printf("%d\n", pop());
//	printf("%d\n", pop());
//	printf("%d\n", pop());
//	printf("%d\n", is_empty());
//}
