//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//#define MAZE_SIZE 6
//#define MAX_STACK_SIZE 100
//
//typedef struct
//{
//	short r;	//��
//	short c;	//��
//}element;
//
//typedef struct
//{
//	element stack[MAX_STACK_SIZE];
//	int top;
//}StackType;
//
//element here = { 1, 0 }, entry = { 1, 0 };
//
//
////���� �ʱ�ȭ �Լ�
//void init(StackType *s)
//{
//	s->top = -1;
//}
//
////���� ���� ���� �Լ�
//int is_empty(StackType *s)
//{
//	return (s->top == -1);
//}
//
////��ȭ ���� ���� �Լ�
//int is_full(StackType *s)
//{
//	return (s->top == MAX_STACK_SIZE - 1);
//}
//
////���� �Լ�
//void push(StackType *s, element item)
//{
//	if (is_full(s))
//	{
//		printf("�޸� ���� ����");
//		return;
//	}
//	else s->stack[++(s->top)] = item;
//}
//
////���� �Լ�
//element pop(StackType *s)
//{
//	if (is_empty(s))
//	{
//		printf("�޸� ���� ����");
//		exit(1);
//	}
//	else return s->stack[(s->top)--];
//}
//
////��ũ �Լ�
//element peek(StackType *s)
//{
//	if (is_empty(s))
//	{
//		printf("�޸� ���� ����");
//		exit(1);
//	}
//	else return s->stack[s->top];
//}
//
//char maze[MAZE_SIZE][MAZE_SIZE] =
//{
//	{'1', '1', '1', '1', '1', '1'},
//	{'e', '0', '1', '0', '0', '1'},
//	{'1', '0', '0', '0', '1', '1'},
//	{'1', '0', '1', '0', '1', '1'},
//	{'1', '0', '1', '0', '0', 'x'},
//	{'1', '1', '1', '1', '1', '1'},
//};
//
////����Ʈ ����
//void outinfo(StackType *s)
//{
//	printf("\n\n");
//	printf("���� ����\n");
//	for (int i = 0; i < s->top; i++)
//	{
//		printf("%d��° : %d %d \n", i + 1, s->stack[i].c, s->stack[i].r);
//	}
//}
//
////�ǽð� ����Լ�
//void outprint(StackType *s)
//{
//	system("cls");
//
//	for (int i = 0; i < MAZE_SIZE; i++)
//	{
//		for (int j = 0; j < MAZE_SIZE; j++)
//		{
//			printf("%c ", maze[i][j]);
//		}
//		printf("\n");
//	}
//	outinfo(s);
//
//}
////��ġ�� ���ÿ� �����Ѵ�.
//void push_loc(StackType *s, int r, int c)
//{
//	if (r < 0 || c < 0)
//		return;
//
//	if (maze[r][c] != '1' && maze[r][c] != '.')	//���� �ƴϰ� �湮���� �ʾ�����
//	{
//		element tmp;
//		tmp.r = r;
//		tmp.c = c;
//		push(s, tmp);
//
//		outprint(s);
//		_sleep(800);
//	}
//}
//
////���� �ڽ��� ��ġ�� ��Ÿ���� �Ϲ�
//void curPos(element e)
//{
//	
//}
////�� �Լ�
//int main(void)
//{
//	int r, c;
//	StackType s;
//
//	init(&s);
//	here = entry;
//
//	while (maze[here.r][here.c] != 'x')
//	{
//		r = here.r;
//		c = here.c;
//		maze[r][c] = 'P';
//
//		push_loc(&s, r - 1, c);
//		push_loc(&s, r + 1, c);
//		push_loc(&s, r, c - 1);
//		push_loc(&s, r, c + 1);
//		
//		if (is_empty(&s))
//		{
//			printf("����\n");
//			return 0;
//		}
//		else
//		{
//			maze[r][c] = '.';
//
//			here = pop(&s);	//�ٽ� �ڵ� : ���ÿ� �׾� �а� �������� ���� ��ǥ�� ���� �ִ´�.
//		}
//		//printf("����\n");
//	}
//}