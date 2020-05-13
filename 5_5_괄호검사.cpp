#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STACK_SIZE 100
#define FALSE 0
#define TRUE 1

typedef char element;
typedef struct
{
	element stack[MAX_STACK_SIZE];
	int top;
}StackType;

//스택 초기화 함수
void init(StackType *s)
{
	s->top = -1;
}

//공백 상태 검출 함수
int is_empty(StackType *s)
{
	return (s->top == -1);
}

//포화 상태 검출 함수
int is_full(StackType *s)
{
	return (s->top == MAX_STACK_SIZE - 1);
}

//삽입 함수
void push(StackType *s, element item)
{
	if (is_full(s))
	{
		printf("메모리 참조 에러");
		return;
	}
	else s->stack[++(s->top)] = item;
}

//삭제 함수
element pop(StackType *s)
{
	if (is_empty(s))
	{
		printf("메모리 참조 에러");
		exit(1);
	}
	else return s->stack[(s->top)--];
}

//피크 함수
element peek(StackType *s)
{
	if (is_empty(s))
	{
		printf("메모리 참조 에러");
		exit(1);
	}
	else return s->stack[s->top];
}

//괄호 검사 함수
int check_matching(char *in)
{
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);		//n = 문자열의 길이

	init(&s);					//스택의 초기화

	for (i = 0; i < n; i++)
	{
		ch = in[i];				//ch = 다음문자
		switch (ch)
		{
		case '(': case '[' : case '{':
			push(&s, ch);
			break;
		case ')':case ']': case '}':
			if (is_empty(&s)) return FALSE;
			else
			{
				open_ch = pop(&s);
				if ((open_ch == '(' && ch != ')') || (open_ch == '{' && ch != '}') || (open_ch == '[' && ch != ']'))		//총 6개의 배열이 있으면 1 2 3 3 2 1 ( 3 의 경계선에서 만나면 끝이라는걸 알린다.)!
					return FALSE;
			}
			break;
		}
	}
	if(!is_empty(&s)) return FALSE;	//스택에 남아 있으면 옲
	return TRUE;
}
//주 함수
int main(void)
{
	if (check_matching("{A[(i+1)]=0;}") == TRUE)	printf("괄호검사성공\n");
	else printf("괄호검사실패\n");
}