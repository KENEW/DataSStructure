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

//�ʱ�ȭ �Լ�
void init(linkedstacktype *s)
{
	s->top = NULL;
}

//���� ���� ���� �Լ�
int is_empty(linkedstacktype *s)
{
	return (s->top == NULL);
 }

//���� �Լ�
void push(linkedstacktype *s, element item)
{
	stacknode *temp = (stacknode *)malloc(sizeof(StackNode));
	if (temp = NULL)
	{
		printf("�޸� �Ҵ� ����\n");
		return;
	}
	else
	{
		temp->item = item;
		temp->link = s->top;
		s->top = temp;
	}
}

//���� �Լ�
element pop(linkedstacktype *s)
{
	if (is_empty(s))
	{
		printf("������ �������\n");
		exit(1);
	}
	else
	{
		stacknode *temp = s->top;
		element item = temp->item;

		s->top = s->top->link;	//�� �ڸ��� �迭�� ��ġ�� �ȵǴϱ� �ӽ� ����ü ������ ���� �Űܵ� ������ �޸� ��ü�� �Ѵ�.
		free(temp);
		return item;
	}
}

//��ũ �Լ�
element peek(linkedstacktype *s)
{
	if (is_empty(s))
	{
		printf("������ �������\n");
		exit(1);
	}
	else
	{
		return s->top->item;
	}
}

//�� �Լ�
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