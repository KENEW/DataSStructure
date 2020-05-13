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

//���� �ʱ�ȭ �Լ�
void init(StackType *s)
{
	s->top = -1;
}

//���� ���� ���� �Լ�
int is_empty(StackType *s)
{
	return (s->top == -1);
}

//��ȭ ���� ���� �Լ�
int is_full(StackType *s)
{
	return (s->top == MAX_STACK_SIZE - 1);
}

//���� �Լ�
void push(StackType *s, element item)
{
	if (is_full(s))
	{
		printf("�޸� ���� ����");
		return;
	}
	else s->stack[++(s->top)] = item;
}

//���� �Լ�
element pop(StackType *s)
{
	if (is_empty(s))
	{
		printf("�޸� ���� ����");
		exit(1);
	}
	else return s->stack[(s->top)--];
}

//��ũ �Լ�
element peek(StackType *s)
{
	if (is_empty(s))
	{
		printf("�޸� ���� ����");
		exit(1);
	}
	else return s->stack[s->top];
}

//��ȣ �˻� �Լ�
int check_matching(char *in)
{
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);		//n = ���ڿ��� ����

	init(&s);					//������ �ʱ�ȭ

	for (i = 0; i < n; i++)
	{
		ch = in[i];				//ch = ��������
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
				if ((open_ch == '(' && ch != ')') || (open_ch == '{' && ch != '}') || (open_ch == '[' && ch != ']'))		//�� 6���� �迭�� ������ 1 2 3 3 2 1 ( 3 �� ��輱���� ������ ���̶�°� �˸���.)!
					return FALSE;
			}
			break;
		}
	}
	if(!is_empty(&s)) return FALSE;	//���ÿ� ���� ������ ��
	return TRUE;
}
//�� �Լ�
int main(void)
{
	if (check_matching("{A[(i+1)]=0;}") == TRUE)	printf("��ȣ�˻缺��\n");
	else printf("��ȣ�˻����\n");
}