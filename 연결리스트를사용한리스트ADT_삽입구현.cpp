//#include<stdio.h>
//#include<malloc.h>
//#include<stdio.h>
//#include<limits.h>
//
//#define FALSE 0
//#define TRUE 1
//
////readme : ADT(Abstract Data Type �߻� ������ Ÿ��)
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
//	ListNode *head;	//��� ������
//	int length;		//����� ���
//}linkedlisttype;
//
//void error()
//{
//	printf("�޸� �Ҵ� ����\n");
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
////����Ʈ �ȿ��� pos ��ġ�� ��带 ��ȯ�Ѵ�.
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
////phead ����Ʈ�� ��� �������� ������
////p ������
////new_node ���Ե� ���
//void insert_node(listnode **phead, listnode *p, listnode *new_node)
//{
//	if (*phead == NULL)	//���� ����Ʈ�� ���
//	{
//		new_node->link = NULL;
//		*phead = new_node;
//	}
//	else if (p == NULL)	//p�� NULL�̸� ù ��° ���� ����
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
////phead ��������Ϳ� ���� ������
////p ������ ����� ���� ���
////removed ������ ���
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
////�־��� ��ġ�� �����͸� �����Ѵ�.
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
////����Ʈ�� ���� �����͸� �����Ѵ�.
//void add_last(linkedlisttype *list, element data)
//{
//	add(list, get_length(list), data);
//}
//
////����Ʈ�� ó���� �����͸� �����Ѵ�.
//void add_first(linkedlisttype *list, element data)
//{
//	add(list, 0, data);
//}
//
////�־��� ��ġ�� �����͸� �����Ѵ�.
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
////�־��� ��ġ�� �ش��ϴ� �����͸� ��ȯ�Ѵ�.
//element get_entry(linkedlisttype *list, int pos)
//{
//	listnode * p;
//	if (pos >= list->length) error();
//	p = get_node_at(list, pos);
//	return p->data;
//}
//
////��� ��带 �����Ѵ�.
//void clear(linkedlisttype *list)
//{
//	int i;
//	for (i = 0; i < list->length; i++)
//		del(list, i);
//}
//
////������ ������ ����Ѵ�.
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
////������ ���� s�� ��带 ã�´�.
//int is_in_list(linkedlisttype *list, element item)
//{
//	listnode *p;
//	p = list->head;	//��� �����Ϳ������� �����Ѵ�.
//	while ((p != NULL))
//	{
//		if (p->data == item)	break;	//����� �����Ͱ� item�̸�
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
//	printf("%s\n", is_in_list(&list1, 20) == TRUE ? "����" : "����");
//	printf("%d\n", get_entry(&list1, 0));
//
//	return 0;
//}
//
//
//
