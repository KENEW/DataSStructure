#include<stdio.h>
#include<malloc.h>
#include<stdio.h>
#include<limits.h>
#include<string.h>

#define FALSE 0
#define TRUE 1

#define MAX_CHAR_PER_LINE 1000
#define MAX_NAME 256

void display(linkedlisttype *buffer);
void clear(linkedlisttype *list);
element get_entry(linkedlisttype *list, int pos);
void del(linkedlisttype *list, int pos);
void add_first(linkedlisttype *list, element data);
void add_last(linkedlisttype *list, element data);
void add(linkedlisttype *list, int position, element data);
void remove_node(listnode **phead, listnode *p, listnode *removed);
void insert_node(listnode **phead, listnode *p, listnode *new_node);
void do_command(linkedlisttype *buffer, char command);
void insert_line(linkedlisttype *buffer);
void delete_line(linkedlisttype *buffer);
void write_file(linkedlisttype *buffer);
void read_file(linkedlisttype *buffer);
listnode *get_node_at(linkedlisttype *list, int pos);
int get_length(linkedlisttype *list);
int is_empty(linkedlisttype *list);
void init(linkedlisttype *list);
void warning();
void help();
void error();

typedef struct
{
	char a[MAX_CHAR_PER_LINE];
}element;

typedef struct ListNode
{
	element data;
	struct ListNode *link;
}listnode;

typedef struct LinkedListType
{
	ListNode *head;	//��� ������
	int length;		//����� ���
}linkedlisttype;

void error()
{
	printf("�޸� �Ҵ� ����\n");
	//exit(1);
}

void help()
{
	printf("*************\n");
	printf("i: �Է�\n");
	printf("d: ����\n");
	printf("r: �����ϱ�\n");
	printf("w: ���Ͼ���\n");
	printf("q: ����\n");
	printf("*************\n");
}

void warning()
{
	printf("Warning!\n");
}

void init(linkedlisttype *list)
{
	if (list == NULL) return;
	list->length = 0;
	list->head = NULL;
}

int is_empty(linkedlisttype *list)
{
	if (list->head == NULL) return 1;
	else return 0;
}

int get_length(linkedlisttype *list)
{
	return list->length;
}

//����Ʈ �ȿ��� pos ��ġ�� ��带 ��ȯ�Ѵ�.
listnode *get_node_at(linkedlisttype *list, int pos)
{
	int i;
	listnode *tmp_node = list->head;

	if (pos < 0) return NULL;
	for (i = 0; i < pos; i++)
	{
		tmp_node = tmp_node->link;
	}
	return tmp_node;
}

//��ũ ���Ϸκ��� �����͸� �д´�.
void read_file(linkedlisttype *buffer)
{
	char fname[MAX_NAME];
	FILE *fd;
	element p;

	if (!is_empty(buffer))
	{
		clear(buffer);
	}
	init(buffer);

	printf("���� �̸�: ");
	scanf_s("%s", fname);
	if ((fd = fopen(fname, "r")) == NULL)
	{
		warning();
		return;
	}
	while (fgets(p.a, MAX_CHAR_PER_LINE, fd))
	{
		add_last(buffer, p);
	}
	fclose(fd);
	display(buffer);
}

//���ۿ� �ִ� �����͸� ��ũ ���Ͽ� ����.
void write_file(linkedlisttype *buffer)
{
	FILE *fd;
	char fname[MAX_NAME];
	element p;
	int i;

	printf("���� �̸�: ");
	scanf_s("%s", fname);
	if ((fd = fopen(fname, "w")) == NULL)
	{
		printf("������ ���������ϴ�.\n");
		return;
	}
	for (i = 0; i < get_length(buffer); i++)
	{
		p = get_entry(buffer, i);
		fputs(p.a, fd);
	}
	fclose(fd);
	display(buffer);
}

//�ϳ��� ������ �����.
void delete_line(linkedlisttype *buffer)
{
	int position;

	if (is_empty(buffer))
	{
		printf("���� ������ �����ϴ�.\n");
	}
	else
	{
		printf("����� ���� ���ι�ȣ�� �Է��ϼ���\n");
		scanf_s("%d", &position);
	}
	display(buffer);
}

//�ϳ��� ������ �����Ѵ�.
void insert_line(linkedlisttype *buffer)
{
	int position;
	char line[MAX_CHAR_PER_LINE];
	element p;
	
	printf("�Է����ȣ�� �Է��ϼ���\n");
	scanf_s("%d", &position);

	printf("������ �Է��ϼ���: ");
	fflush(stdin);
	fgets(line, MAX_CHAR_PER_LINE, stdin);
	strcpy(p.a, line);
	add(buffer, position, p);
	display(buffer);
}

void do_command(linkedlisttype *buffer, char command)
{
	switch (command)
	{
	case 'd':
		delete_line(buffer);
		break;
	case 'i':
		insert_line(buffer);
		break;
	case 'r':
		read_file(buffer);
		break;
	case 'w':
		write_file(buffer);
		break;
	case 'q':
		break;
	}
}

//phead ����Ʈ�� ��� �������� ������
//p ������
//new_node ���Ե� ���
void insert_node(listnode **phead, listnode *p, listnode *new_node)
{
	if (*phead == NULL)	//���� ����Ʈ�� ���
	{
		new_node->link = NULL;
		*phead = new_node;
	}
	else if (p == NULL)	//p�� NULL�̸� ù ��° ���� ����
	{
		new_node->link = *phead;
		*phead = new_node;
	}
	else
	{
		new_node->link = p->link;
		p->link = new_node;
	}
}

//phead ��������Ϳ� ���� ������
//p ������ ����� ���� ���
//removed ������ ���
void remove_node(listnode **phead, listnode *p, listnode *removed)
{
	if (p != NULL)
	{
		*phead = (*phead)->link;
	}
	else
	{
		p->link = removed->link;
	}
	free(removed);
}

//�־��� ��ġ�� �����͸� �����Ѵ�.
void add(linkedlisttype *list, int position, element data)
{
	listnode *p;

	if ((position >= 0) && (position <= list->length))
	{
		listnode *node = (listnode *)malloc(sizeof(listnode));

		if (node == NULL) error();

		node->data = data;
		p = get_node_at(list, position - 1);
		insert_node(&(list->head), p, node);
		list->length++;
	}
}

//����Ʈ�� ���� �����͸� �����Ѵ�.
void add_last(linkedlisttype *list, element data)
{
	add(list, get_length(list), data);
}

//����Ʈ�� ó���� �����͸� �����Ѵ�.
void add_first(linkedlisttype *list, element data)
{
	add(list, 0, data);
}

//�־��� ��ġ�� �����͸� �����Ѵ�.
void del(linkedlisttype *list, int pos)
{
	if (!is_empty(list) && (pos >= 0) && (pos < list->length))
	{
		listnode *p = get_node_at(list, pos - 1);
		remove_node(&(list->head), p, (p != NULL) ? p->link : NULL);
		list->length--;
	}
}

//�־��� ��ġ�� �ش��ϴ� �����͸� ��ȯ�Ѵ�.
element get_entry(linkedlisttype *list, int pos)
{
	listnode * p;
	if (pos >= list->length) error();
	p = get_node_at(list, pos);
	return p->data;
}

//��� ��带 �����Ѵ�.
void clear(linkedlisttype *list)
{
	int i;

	for (i = 0; i < list->length; i++)
		del(list, i);
}

//������ ������ ����Ѵ�.
void display(linkedlisttype *buffer)
{
	int i;
	listnode *tmp_node = buffer->head;

	printf("*******************\n");
	for (i = 0; i < buffer->length; i++)
	{
		printf("%d", tmp_node->data.a);
		tmp_node = tmp_node->link;
	}
	printf("*********************\n");
}

//���� ������ ���� ���α׷�
int main(void)
{
	char command;
	linkedlisttype buffer;

	init(&buffer);

	do {
		help();
		command = getchar();
		do_command(&buffer, command);
		fflush(stdin);
	} while (command != 'q');
}
