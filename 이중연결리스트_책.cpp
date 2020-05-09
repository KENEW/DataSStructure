#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>

typedef int element;

typedef struct DlistNode
{
	element data;				//������ ������ �ʵ�
	struct DlistNode *llink;	//���� ��ũ �ʵ�
	struct DlistNode *rlink;	//������ ��ũ �ʵ�
}dlistnode;

void init(dlistnode *phead)
{
	phead->llink = phead;	//�ڱ� �ּҷ� �ʱ�ȭ
	phead->rlink = phead;
}

void display(dlistnode *phead)
{
	dlistnode *p;
	for (p = phead->rlink; p != phead; p->rlink)	//phead�� �ƴϸ� ��� ������ ��ũ �ʵ�� ����
	{
		printf("<--- l %x l %d l %x l ---->\n", p->llink, p->data, p->rlink);
	}
	printf("\n");
}

void reverse_display(dlistnode* phead)
{
	dlistnode *p = phead;

	while (p != NULL)
	{
		printf("%d", p->data);
		p = p->llink;
	}
	printf("\n");
}
void dinsert_node(dlistnode *before, dlistnode *new_node)
{
	new_node->llink = before;	//���ο� dlistnode�� ���� ��ũ �ʵ带 head_node ��ũ�� ����
	new_node->rlink = before->rlink;

	before->rlink->llink = new_node;
	before->rlink = new_node;
}

void dremove_node(dlistnode *phead_node, dlistnode *removed)
{
	if (removed == phead_node) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

int main(void)
{
	dlistnode head_node;
	dlistnode *p[10];
	int i;
	init(&head_node);

	for (i = 0; i < 5; i++)
	{
		p[i] = (dlistnode *)malloc(sizeof(dlistnode));
		p[i]->data = i;
		//��� ���� �����ʿ� ����
		dinsert_node(&head_node, p[i]);
	}
	dremove_node(&head_node, p[4]);
	display(&head_node);

	return 0;
}
