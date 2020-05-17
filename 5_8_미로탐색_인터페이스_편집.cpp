//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//#define MAZE_SIZE 6
//#define MAX_STACK_SIZE 100
//
//typedef struct
//{
//	short r;	//행
//	short c;	//열
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
////스택 초기화 함수
//void init(StackType *s)
//{
//	s->top = -1;
//}
//
////공백 상태 검출 함수
//int is_empty(StackType *s)
//{
//	return (s->top == -1);
//}
//
////포화 상태 검출 함수
//int is_full(StackType *s)
//{
//	return (s->top == MAX_STACK_SIZE - 1);
//}
//
////삽입 함수
//void push(StackType *s, element item)
//{
//	if (is_full(s))
//	{
//		printf("메모리 참조 에러");
//		return;
//	}
//	else s->stack[++(s->top)] = item;
//}
//
////삭제 함수
//element pop(StackType *s)
//{
//	if (is_empty(s))
//	{
//		printf("메모리 참조 에러");
//		exit(1);
//	}
//	else return s->stack[(s->top)--];
//}
//
////피크 함수
//element peek(StackType *s)
//{
//	if (is_empty(s))
//	{
//		printf("메모리 참조 에러");
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
////프론트 정보
//void outinfo(StackType *s)
//{
//	printf("\n\n");
//	printf("현재 스택\n");
//	for (int i = 0; i < s->top; i++)
//	{
//		printf("%d번째 : %d %d \n", i + 1, s->stack[i].c, s->stack[i].r);
//	}
//}
//
////실시간 출력함수
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
////위치를 스택에 삽입한다.
//void push_loc(StackType *s, int r, int c)
//{
//	if (r < 0 || c < 0)
//		return;
//
//	if (maze[r][c] != '1' && maze[r][c] != '.')	//벽이 아니고 방문되지 않았으면
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
////현재 자신의 위치를 나타내는 하뭇
//void curPos(element e)
//{
//	
//}
////주 함수
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
//			printf("실패\n");
//			return 0;
//		}
//		else
//		{
//			maze[r][c] = '.';
//
//			here = pop(&s);	//핵심 코드 : 스택에 쌓아 둔걸 빼가지고 현재 좌표에 집어 넣는다.
//		}
//		//printf("성공\n");
//	}
//}