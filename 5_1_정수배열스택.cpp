//#include<stdio.h>
//#include<stdlib.h>
//
//#define MAX_STACK_SIZE 100
//typedef int element;
//element stack[MAX_STACK_SIZE];
//int top = -1;
//
////���� ���� ���� ����
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
//		stack[top++] = item;
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
////�� �Լ�
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
