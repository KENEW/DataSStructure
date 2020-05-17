#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int element;

typedef struct DlistNode	//����� Ÿ��
{
	element data;
	struct DlistNode *llink;
	struct DlistNode *rlink;
}dlistnode;

typedef struct DequeType	//���� Ÿ��
{
	DlistNode *head;
	DlistNode *tail;
}dequetype;

//���� ó�� �Լ�
void error()
{
	printf("�޸� ���� ����");
	exit(1);
}

//�ʱ�ȭ �Լ�
void init(dequetype *dq)
{
	dq->head = NULL;
	dq->tail = NULL;
}

//����ִ��� Ȯ��
int is_empty(dequetype *dq)
{
	return (dq->head == NULL);
}

dlistnode *create_node(dlistnode *llink, element item, dlistnode *rlink)
{
	dlistnode *node = (dlistnode *)malloc(sizeof(dlistnode));

	if (node == NULL) error();
	node->llink = llink;
	node->data = item;
	node->rlink = rlink;

	return node;
}
void add_rear(dequetype *dq, element item)
{
	dlistnode *new_node = create_node(dq->tail, item, NULL);

	if (is_empty(dq))
	{
		dq->head = new_node;
	}
	else
	{
		dq->tail = new_node;
		dq->tail->rlink = new_node;
	}

	dq->tail = new_node;
}

void add_front(dequetype *dq, element item)
{
	dlistnode *new_node = create_node(NULL, item, dq->head);

	if (is_empty(dq))
		dq->tail = new_node;

	else
	{
		dq->head->llink = new_node;
	}

	dq->head = new_node;
}

//���ܿ����� ����
element delete_front(dequetype *dq)
{
	element item;
	dlistnode *removed_node;

	if (is_empty(dq))
		error();
	else
	{
		removed_node = dq->head;		//������ ���
		item = removed_node->data;		//������ ����
		dq->tail = dq->head->rlink;		//���� ������ ����

		free(removed_node);

		if (dq->head == NULL)			//���� �����̸�
			dq->tail = NULL;
		else
			dq->head->llink = NULL;
	}
	
	return item;
}

//�Ĵܿ����� ����
element delete_rear(dequetype *dq)
{
	element item;
	dlistnode *removed_node;

	if (is_empty(dq)) error();
	else
	{
		removed_node = dq->tail;		//������ ���
		item = removed_node->data;		//������ ����
		dq->tail = dq->tail->llink;		//���� ������ ����

		free(removed_node);				//�޸� ���� �ݳ�

		if (dq->tail == NULL)			//���� �����̸�
			dq->head = NULL;
		else
			dq->tail->rlink = NULL;
	}
	return item;
}

void display(dequetype *dq)
{
	dlistnode *p;
	
	printf("(");
	
	for (p = dq->head; p != NULL; p = p->rlink)
		printf("%d", p->data);

	printf(")\n");
}

int main(void)
{
	dequetype deque;

	init(&deque);

	add_front(&deque, 10);		//���ܿ� 10 ����
	add_front(&deque, 20);		//���ܿ� 20 ����
	add_rear(&deque, 30);		//�Ĵܿ� 30 ����

	display(&deque);			//���� ���� ���

	delete_front(&deque);		//���ܿ��� ����
	delete_rear(&deque);		//�Ĵܿ��� ����

	display(&deque);			//���� ���� ���
}