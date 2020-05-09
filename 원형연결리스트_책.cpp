//#include<stdio.h>
//#include<stdlib.h>
//
//typedef int element;
//
//typedef struct ListNode
//{
//	element data;
//	ListNode *link;
//}listnode;
//
//void error()
//{
//	printf("메모리 할당 에러!\n");
//	exit(1);
//}
//
////노드를 동적으로 생성하는 프로그램
//listnode *create_node(element data, listnode *link)
//{
//	listnode *new_node;
//	new_node = (listnode*)malloc(sizeof(listnode));
//	if (new_node == NULL) error();
//	new_node->data = data;
//	new_node->link = link;
//
//	return new_node;
//}
//
////phead 리스트의 헤드포인터의 포인터
////node 삽입될 노드
//void insert_first(listnode **phead, listnode *node)
//{
//	if (*phead == NULL)
//	{
//		*phead = node;
//		node->link = node;
//	}
//	else
//	{
//		node->link = (*phead)->link;
//		(*phead)->link = node;
//	}
//}
//
////phead 리스트의 헤드 포인터의 포인터
////node 삽입될 노드
//void insert_last(listnode **phead, listnode *node)
//{
//	if (*phead == NULL)
//	{
//		*phead = node;
//		node->link = node;
//	}
//	else
//	{
//		node->link = (*phead)->link;
//		(*phead)->link = node;
//		*phead = node;
//	}
//}
//
////phead 헤드 포인터에 대한 포인터
////p 삭제될 노드의 선행 노드
////removed 삭제될 노드
//
//void removed_node(listnode **phead, listnode *p, listnode *removed)
//{
//	if (p == NULL)
//	{
//		*phead = (*phead)->link;
//	}
//	else
//	{
//		(*p).link = removed->link;
//	}
//	free(removed);
//}
//
//void display(listnode *head)
//{
//	listnode *p;
//	if (head == NULL) return;
//
//	p = head;
//
//	do {
//		printf("%d->", p->data);
//		p = p->link;
//	} while (p != NULL);
//}
//
//int main(void)
//{
//	listnode *list1 = NULL;
//
//	//list1 = 20->10->30
//	insert_first(&list1, NULL, create_node(10, NULL));
//	insert_first(&list1, NULL, create_node(20, NULL));
//	insert_last(&list1, NULL, create_node(30, NULL));
//	display(list1);
//
//	return 0;
//}
