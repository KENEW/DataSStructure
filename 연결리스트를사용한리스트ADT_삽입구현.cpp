//#include<stdio.h>
//#include<malloc.h>
//#include<stdio.h>
//#include<limits.h>
//
//#define FALSE 0
//#define TRUE 1
//
////readme : ADT(Abstract Data Type 추상 데이터 타입)
//
//typedef int element;
//
//typedef struct ListNode
//{
//	element data;
//	struct ListNode *link;
//}listnode;
//
//typedef struct LinkedListType
//{
//	ListNode *head;	//헤드 포인터
//	int length;		//노드의 계수
//}linkedlisttype;
//
//void error()
//{
//	printf("메모리 할당 에러\n");
//	//exit(1);
//}
//
//void init(linkedlisttype *list)
//{
//	if (list == NULL) return;
//	list->length = 0;
//	list->head = NULL;
//}
//int is_empty(linkedlisttype *list)
//{
//	if (list->head == NULL) return 1;
//	else return 0;
//}
//
//int get_length(linkedlisttype *list)
//{
//	return list->length;
//}
//
////리스트 안에서 pos 위치의 노드를 반환한다.
//listnode *get_node_at(linkedlisttype *list, int pos)
//{
//	int i;
//	listnode *tmp_node = list->head;
//
//	if (pos < 0) return NULL;
//	for (i = 0; i < pos; i++)
//	{
//		tmp_node = tmp_node->link;
//	}
//	return tmp_node;
//}
//
////phead 리스트의 헤드 포인터의 포인터
////p 선행노드
////new_node 삽입될 노드
//void insert_node(listnode **phead, listnode *p, listnode *new_node)
//{
//	if (*phead == NULL)	//공백 리스트인 경우
//	{
//		new_node->link = NULL;
//		*phead = new_node;
//	}
//	else if (p == NULL)	//p가 NULL이면 첫 번째 노드로 삽입
//	{
//		new_node->link = *phead;
//		*phead = new_node;
//	}
//	else
//	{
//		new_node->link = p->link;
//		p->link = new_node;
//	}
//}
//
////phead 헤드포인터에 대한 포인터
////p 삭제될 노드의 선행 노드
////removed 삭제될 노드
//void remove_node(listnode **phead, listnode *p, listnode *removed)
//{
//	if (p != NULL)
//	{
//		*phead = (*phead)->link;
//	}
//	else
//	{
//		p->link = removed->link;
//	}
//	free(removed);
//}
//
////주어진 위치에 데이터를 삽입한다.
//void add(linkedlisttype *list, int position, element data)
//{
//	listnode *p;
//
//	if ((position >= 0) && (position <= list->length))
//	{
//		listnode *node = (listnode *)malloc(sizeof(listnode));
//
//		if (node == NULL) error();
//
//		node->data = data;
//		p = get_node_at(list, position - 1);
//		insert_node(&(list->head), p, node);
//		list->length++;
//	}
//}
//
////리스트의 끝에 데이터를 삽입한다.
//void add_last(linkedlisttype *list, element data)
//{
//	add(list, get_length(list), data);
//}
//
////리스트의 처음에 데이터를 삽입한다.
//void add_first(linkedlisttype *list, element data)
//{
//	add(list, 0, data);
//}
//
////주어진 위치의 데이터를 삭제한다.
//void del(linkedlisttype *list, int pos)
//{
//	if (!is_empty(list) && (pos >= 0) && (pos < list->length))
//	{
//		listnode *p = get_node_at(list, pos - 1);
//		remove_node(&(list->head), p, (p != NULL) ? p->link : NULL);
//		list->length--;
//	}
//}
//
////주어진 위치에 해당하는 데이터를 반환한다.
//element get_entry(linkedlisttype *list, int pos)
//{
//	listnode * p;
//	if (pos >= list->length) error();
//	p = get_node_at(list, pos);
//	return p->data;
//}
//
////모든 노드를 삭제한다.
//void clear(linkedlisttype *list)
//{
//	int i;
//	for (i = 0; i < list->length; i++)
//		del(list, i);
//}
//
////버퍼의 내용을 출력한다.
//void display(linkedlisttype *list)
//{
//	int i;
//	listnode *node = list->head;
//	printf("(");
//	for (i = 0; i < list->length; i++)
//	{
//		printf("%d", node->data);
//		node = node->link;
//	}
//	printf(")\n");
//}
//
////데이터 값이 s인 노드를 찾는다.
//int is_in_list(linkedlisttype *list, element item)
//{
//	listnode *p;
//	p = list->head;	//헤드 포인터에서부터 시작한다.
//	while ((p != NULL))
//	{
//		if (p->data == item)	break;	//노드의 데이터가 item이면
//		p = p->link;
//	}
//	if (p == NULL) return FALSE;
//	else return TRUE;
//}
//
//int main(void)
//{
//	linkedlisttype list1;
//
//	init(&list1);
//	add(&list1, 0, 20);
//	add_last(&list1, 30);
//	add_first(&list1, 30);
//	add_last(&list1, 40);
//
//	//list1 = (10, 20, 30, 40)
//	display(&list1);
//
//	//list1 = (10, 20, 30)
//	del(&list1, 3);
//	display(&list1);
//
//	//list1 = (20, 30)
//	del(&list1, 0);
//	display(&list1);
//
//	printf("%s\n", is_in_list(&list1, 20) == TRUE ? "성공" : "실패");
//	printf("%d\n", get_entry(&list1, 0));
//
//	return 0;
//}
//
//
//
