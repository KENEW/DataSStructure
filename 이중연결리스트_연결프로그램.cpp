#include<stdio.h>
#include<stdlib.h>

//연결 리스트의 노드의 구조
typedef struct ListNode
{
	int coef;		//계수
	int expon;		//항
	struct ListNode *link;
}listnode;

//연결 리스트 헤더
typedef struct ListHeader
{
	int length;
	listnode *head;
	listnode *tail;
}listheader;

//초기화 함수
void init(listheader *plist)
{
	plist->length = 0;
	plist->head = NULL; 
	plist->tail = NULL;
}

//오류 처리 함수
void error()
{
	printf("메모리 참조 에러\n");
	exit(1);
}

//plist는 연결리스트의 헤더를 가리키는 포인터, coef는 계수
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

	//a나 b중의 하나가 먼저 끝나게 되면 남아 있는 항들을 모두 결과 다항식으로 복사
	if (a != NULL)
		for (; a != NULL; a = a->link)
			insert_node_last(plist3, a->coef, a->expon);
	if (b != NULL)
		for (; b != NULL; b = b->link)
			insert_node_last(plist3, b->coef, b->expon);
}

//다항식 출력 함수
void poly_print(listheader *plist)
{
	listnode *p = plist->head;
	for (; p; p = p->link)	printf("%d %d\n", p->coef, p->expon);
}

//이중 연결 리스트의 응용 테스트 프로그램
int main(void)
{
	listheader list1, list2, list3;

	//연결 리스트의 초기화
	init(&list1);
	init(&list2);
	init(&list3);

	//다항식 1을 생성
	insert_node_last(&list1, 3, 12);
	insert_node_last(&list1, 2, 8);
	insert_node_last(&list1, 1, 10);

	//다항식 2를 생성
	insert_node_last(&list2, 8, 12);
	insert_node_last(&list2, -3, 10);
	insert_node_last(&list2, 10, 6);

	//다항식3 = 다항식1 + 다항식2
	poly_add(&list1, &list2, &list3);
	poly_print(&list3);

}