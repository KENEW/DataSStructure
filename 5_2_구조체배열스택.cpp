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
////���� ���� ���� �Լ�
//int is_empty()
//{
//	return (top == -1);
//}
//
////��ȭ ���� ���� �Լ�
//int is_full()
//{
//	return (top == MAX_STACK_SIZE - 1);
//}
//
////���� �Լ�
//void push(element item)
//{
//	if (is_full())
//	{
//		printf("�޸� ���� ����");
//		return;
//	}
//	else
//	{
//		stack[++top] = item;
//	}
//}
//
////���� �Լ�
//element pop()
//{
//	if (is_empty())
//	{
//		printf("�޸� ���� ����");
//		exit(1);
//	}
//	else return stack[top--];
//}
//
////��ũ �Լ�
//element peek()
//{
//	if (is_empty())
//	{
//		printf("�޸� ���� ����");
//		exit(1);
//	}
//	else return stack[top];
//}
//
////�� �Լ�
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