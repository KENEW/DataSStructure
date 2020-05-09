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
//	printf("�޸� �Ҵ� ����!\n");
//	exit(1);
//}
//
////phead ����Ʈ�� ��� �������� ������
////p ���� ���
////new_node ���Ե� ���
//void insert_node(listnode **phead, listnode *p, listnode *new_node)
//{
//	if (*phead == NULL)
//	{
//		new_node->link = NULL;
//		*phead = new_node;
//	}
//	else if (p == NULL)
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
////phead ��� �����Ϳ� ���� ������
////p ������ ����� ���� ���
////removed ������ ���
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
//	listnode *p = head;
//	while (p != NULL)
//	{
//		printf("%d->", p->data);
//		p = p->link;
//	}
//	printf("\n");
//}
//
//void display_recur(listnode *head)
//{
//	listnode *p = head;
//	if (p != NULL)
//	{
//		printf("%d->", p->data);
//		display_recur(p->link);
//	}
//}
//
//listnode *search(listnode *head, int x)
//{
//	listnode *p = head;
//	while (p != NULL)
//	{
//		if (p->data == x)	return p;	//Ž�� ����
//		p = p->link;
//	}
//	return p;
//}
//
//listnode *concat(listnode *head1, listnode *head2)
//{
//	listnode *p;
//	if (head1 == NULL) return head2;
//	else if (head2 == NULL) return head1;
//	else
//	{
//		p = head1;
//		while (p->link != NULL)
//		{
//			p = p->link;
//			p->link = head2;
//			return head1;
//		}
//	}
//}
//
//listnode *reverse(listnode *head)
//{
//	listnode *p, *q, *r;
//	p = head;
//	q = NULL;
//
//	while (p != NULL)
//	{
//		r = q;
//		q = p;
//		p = p->link;
//		q->link = r;
//	}
//}
//
//listnode *create_node(element data, listnode *link)
//{
//	listnode *new_node;
//	new_node = (listnode *)malloc(sizeof(listnode));
//	if (new_node == NULL) error();
//	new_node->data = data;
//	new_node->link = link;
//
//	return new_node;
//}
//
//int main(void)
//{
//	listnode *list1 = NULL, *list2 = NULL;
//	listnode *p;
//	
//	//list1 = 30->20->10
//	insert_node(&list1, NULL, create_node(10, NULL));
//	insert_node(&list1, NULL, create_node(20, NULL));
//	insert_node(&list1, NULL, create_node(30, NULL));
//	display(list1);
//
//	//list1 = 20->10
//	removed_node(&list1, NULL, list1);
//	display(list1);
//
//	//list2 = 80->70->60
//	insert_node(&list2, NULL, create_node(60, NULL));
//	insert_node(&list2, NULL, create_node(70, NULL));
//	insert_node(&list2, NULL, create_node(80, NULL));
//	display(list2);
//
//	//list1 = list1 + list2
//	list1 = concat(list1, list2);
//	display(list1);
//
//	//list1�� ��������
//	list1 = reverse(list1);
//	display(list1);
//
//	//list1���� 20Ž��
//	p = search(list1, 20);
//	printf("Ž������: %d\n", p->data);
//
//	return 0;
//}
