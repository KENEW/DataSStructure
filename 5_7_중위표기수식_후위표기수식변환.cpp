//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#define MAX_STACK_SIZE 100
//typedef char element;
//
//typedef struct
//{
//	element stack[MAX_STACK_SIZE];
//	int top;
//}StackType;
//
////���� �ʱ�ȭ �Լ�
//void init(StackType *s)
//{
//	s->top = -1;
//}
//
////���� ���� ���� �Լ�
//int is_empty(StackType *s)
//{
//	return (s->top == -1);
//}
//
////��ȭ ���� ���� �Լ�
//int is_full(StackType *s)
//{
//	return (s->top == MAX_STACK_SIZE - 1);
//}
//
////���� �Լ�
//void push(StackType *s, element item)
//{
//	if (is_full(s))
//	{
//		printf("�޸� ���� ����");
//		return;
//	}
//	else s->stack[++(s->top)] = item;
//}
//
////���� �Լ�
//element pop(StackType *s)
//{
//	if (is_empty(s))
//	{
//		printf("�޸� ���� ����");
//		exit(1);
//	}
//	else return s->stack[(s->top)--];
//}
//
////��ũ �Լ�
//element peek(StackType *s)
//{
//	if (is_empty(s))
//	{
//		printf("�޸� ���� ����");
//		exit(1);
//	}
//	else return s->stack[s->top];
//}
//
////�������� �켱������ ��ȯ�Ѵ�.
//int prec(char op)
//{
//	switch (op)
//	{
//	case '(': case ')': return 0;
//	case '+': case '-': return 1;
//	case '*': case '/': return 2;
//	}
//	return -1;
//}
//
////���� ǥ�� ���� -> ���� ǥ�� ����
//void infix_to_postfi(char exp[])
//{
//	int i = 0;
//	char ch, top_op;
//	int len = strlen(exp);
//	
//	StackType s;
//	
//	init(&s);
//	for (i = 0; i < len; i++)
//	{
//		ch = exp[i];
//		switch (ch)
//		{
//		case '+':case '-': case '*': case'/':	//������
//			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))	//���ÿ� �ִ� �������� �켱������ �� ũ�ų� ������ ���
//			{
//				printf("%c", pop(&s));
//
//			}
//			push(&s, ch);
//			break;
//
//		case '(':
//			push(&s, ch);
//			break;
//		case ')':
//			top_op = pop(&s);
//			//���� ��ȣ�� ���� ������ ���
//			while (top_op != '(')
//			{
//				printf("%c", top_op);
//				top_op = pop(&s);
//			}
//			break;
//		default:
//			printf("%c", ch);
//			break;
//		}
//	}
//	while (!is_empty(&s))	printf("%c", pop(&s));	//���ÿ� ����� �����ڵ� ���
//}
////�� �Լ�
//int main(void)
//{
//	char ch[50] = "(2+3)*4+9";
//	infix_to_postfi(ch);
//
//	return 0;
//}