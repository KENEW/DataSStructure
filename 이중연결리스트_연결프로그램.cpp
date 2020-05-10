#include<stdio.h>
#include<stdlib.h>

//���� ����Ʈ�� ����� ����
typedef struct ListNode
{
	int coef;		//���
	int expon;		//��
	struct ListNode *link;
}listnode;

//���� ����Ʈ ���
typedef struct ListHeader
{
	int length;
	listnode *head;
	listnode *tail;
}listheader;

//�ʱ�ȭ �Լ�
void init(listheader *plist)
{
	plist->length = 0;
	plist->head = NULL; 
	plist->tail = NULL;
}

//���� ó�� �Լ�
void error()
{
	printf("�޸� ���� ����\n");
	exit(1);
}

//plist�� ���Ḯ��Ʈ�� ����� ����Ű�� ������, coef�� ���
void insert_node_last(listheader *plist, int coef, int expon)
{
	listnode *temp = (listnode *)malloc(sizeof(listnode));
	if (temp == NULL) error();
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;
	if (plist->tail = NULL)
	{
		plist->head = temp;
		plist->tail = temp;
	}
	else
	{
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->length++;
}

//list3 = list1 + list2
void poly_add(listheader *plist1, listheader *plist2, listheader *plist3)
{
	listnode *a = plist1->head;
	listnode *b = plist2->head;
	int sum;

	while (a != NULL || b != NULL)
	{
		if (a->expon == b->expon)
		{
			sum = a->coef + b->coef;
			if (sum != 0) insert_node_last(plist3, sum, a->expon);
			a = a->link;
			b = b->link;
		}
		else if (a->expon > b->expon)
		{
			insert_node_last(plist3, a->coef, b->expon);
			a = a->link;
		}
		else
		{
			insert_node_last(plist3, b->coef, b->expon);
			b = b->link;
		}
	}

	//a�� b���� �ϳ��� ���� ������ �Ǹ� ���� �ִ� �׵��� ��� ��� ���׽����� ����
	if (a != NULL)
		for (; a != NULL; a = a->link)
			insert_node_last(plist3, a->coef, a->expon);
	if (b != NULL)
		for (; b != NULL; b = b->link)
			insert_node_last(plist3, b->coef, b->expon);
}

//���׽� ��� �Լ�
void poly_print(listheader *plist)
{
	listnode *p = plist->head;
	for (; p; p = p->link)	printf("%d %d\n", p->coef, p->expon);
}

//���� ���� ����Ʈ�� ���� �׽�Ʈ ���α׷�
int main(void)
{
	listheader list1, list2, list3;

	//���� ����Ʈ�� �ʱ�ȭ
	init(&list1);
	init(&list2);
	init(&list3);

	//���׽� 1�� ����
	insert_node_last(&list1, 3, 12);
	insert_node_last(&list1, 2, 8);
	insert_node_last(&list1, 1, 10);

	//���׽� 2�� ����
	insert_node_last(&list2, 8, 12);
	insert_node_last(&list2, -3, 10);
	insert_node_last(&list2, 10, 6);

	//���׽�3 = ���׽�1 + ���׽�2
	poly_add(&list1, &list2, &list3);
	poly_print(&list3);

}