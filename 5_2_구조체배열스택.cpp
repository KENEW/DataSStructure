//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//#define MAX_STACK_SIZE 100
//#define MAX_STRING 100
//typedef struct
//{
//	int student_no;
//	char name[MAX_STRING];
//	char address[MAX_STACK_SIZE];
//}element;
//
//element stack[MAX_STACK_SIZE];
//int top = -1;
//
////공백 상태 검출 함수
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
//	{
//		stack[++top] = item;
//	}
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
////피크 함수
//element peek()
//{
//	if (is_empty())
//	{
//		printf("메모리 참조 에러");
//		exit(1);
//	}
//	else return stack[top];
//}
//
////주 함수
//int main(void)
//{
//	element ie, oe;
//
//	strcpy(ie.name, "HONGGILDONG");
//	strcpy(ie.address, "SEOUL");
//	ie.student_no = 200530001;
//	push(ie);
//	oe = pop();
//
//	printf("name: %s\n", oe.name);
//	printf("address: %s\n", oe.address);
//	printf("Student number: %d\n", oe.student_no);
//}