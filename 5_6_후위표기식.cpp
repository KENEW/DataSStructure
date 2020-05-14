//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<cstring>
//#include<iostream>
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
////후위 표기 수식 계산 함수
//int eval(char exp[])
//{
//	int op1, op2, value, i = 0;
//	int len = strlen(exp);
//	char ch;
//
//	StackType s;
//
//	init(&s);
//
//	for (i = 0; i < len; i++)
//	{
//		ch = exp[i];
//		if (ch != '+' && ch != '-' && ch != '*' && ch != '/')
//		{
//			value = ch - '0';	//문자 0은 아스키 코드 값으로 80이다. 0부터 문자로 취급한다. Ex - '8' = 88 , '0' = 80 , 88 - 80 = 8이된다.  // 입력이 파연산자이면
//			push(&s, value);
//		}
//		else //연산자이면 피연산자를 스택에서 제거
//		{
//			op2 = pop(&s);
//			op1 = pop(&s);
//
//			switch(ch)	//연산자이면 피연사자를 스택에서 제거
//			{
//			case '+': push(&s, op1 + op2);	break;
//			case '-': push(&s, op1 - op2);	break;
//			case '*': push(&s, op1 * op2);	break;
//			case '/': push(&s, op1 / op2);	break;
//			}
//		}
//	}
//	return pop(&s);
//}
//
////주 함수
//int main(void)
//{
//	char str[] = "82/3-32*+";
//
//	int result;
//	printf("후위표기식은 82/3-32*+\n");
//	result = eval(str);
//	printf("결과값은 %d\n", result);
//
//	return 0;
//}