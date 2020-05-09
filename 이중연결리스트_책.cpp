#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>

typedef int element;

typedef struct DlistNode
{
	element data;				//정수형 데이터 필드
	struct DlistNode *llink;	//왼쪽 링크 필드
	struct DlistNode *rlink;	//오른쪽 링크 필드
}dlistnode;

void init(dlistnode *phead)
{
	phead->llink = phead;	//자기 주소로 초기화
	phead->rlink = phead;
}

void display(dlistnode *phead)
{
	dlistnode *p;
	for (p = phead->rlink; p != phead; p->rlink)	//phead가 아니면 계속 오른쪽 링크 필드로 접근
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
	new_node->llink = before;	//새로운 dlistnode의 왼쪽 링크 필드를 head_node 링크로 삽입
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
		//헤드 노드와 오른쪽에 삽입
		dinsert_node(&head_node, p[i]);
	}
	dremove_node(&head_node, p[4]);
	display(&head_node);

	return 0;
}
