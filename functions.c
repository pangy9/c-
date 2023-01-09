#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"

void menu() {
	printf("****************************************\n");
	printf("**************������ѡ��****************\n");
	printf("****1.��ʼ��Ϸ            0.�˳���Ϸ****\n");
	printf("****************************************\n");
}

/*
����Ӧ������ȫ����ʼ��Ϊ�����ֵ
*/
void initboard(char board[ROWS][COLS], int row, int col, char set) {
	for (int i = 0;i < row;i++) {
		for (int j = 0;j < col;j++) {
			board[i][j] = set;
		}
	}
}

/*
չʾ������
*/
void showboard(char board[ROWS][COLS], int row, int col) {
	for (int i = 0;i <= row;i++) {
		printf(" %d", i);
	}
	printf("\n");
	for (int i = 1;i <= row;i++) {
		printf(" %d", i);
		for (int j = 1;j <= col;j++) {
			printf(" %c", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

/*
������
*/
void setmine(char board[ROWS][COLS], int row, int col,int cnt) {
	int x = 0, y = 0;
	srand((unsigned int)time(0));
	while (cnt) {
		x = rand() % 9 + 1;//Ҫ����1-9����
		y = rand() % 9 + 1;
		if (board[x][y]=='0') {
			board[x][y] = '1';
			cnt--;
		}
	}
}

int findmine(char board1[ROWS][COLS], char board2[ROWS][COLS], int x, int y,int* win) {
	if (board1[x][y] == '1') return 1;//����
	else  board2[x][y] = board1[x - 1][y - 1] + board1[x - 1][y] + board1[x - 1][y + 1]
		+ board1[x][y - 1] + board1[x][y + 1] + board1[x + 1][y - 1] + board1[x + 1][y]
		+ board1[x + 1][y + 1]  - 7 * '0';
	if(board2[x][y]=='0') clear(board1,board2, x, y,win);
	(*win)++;
		return 0;
}

/*
�ж��Ƿ��ڽ�������Ѿ����,�Ǿͷ���1�����Ƿ���0
*/
int judge(char board[][COLS],int x, int y) {
	if (x<1 || x > ROW || y<1 || y> COL) return 1;
	if (board[x][y] != '*') return 1;
	return 0;
}

/*
���д�������
*/
void clear(char board1[][COLS],char board2[][COLS], int x, int y,int* win) {
	board2[x][y] = '_';
	if (!judge(board2,x-1, y-1)) {
		findmine(board1, board2, x-1, y-1,win);
	}
	if (!judge(board2, x-1, y)) {
		findmine(board1, board2, x-1, y,win);
	}
	if (!judge(board2, x-1, y+1)) {
		findmine(board1, board2, x-1, y+1,win);
	}
	if (!judge(board2, x, y-1)) {
		findmine(board1, board2, x, y-1,win);
	}
	if (!judge(board2, x, y+1)) {
		findmine(board1, board2, x, y+1,win);
	}
	if (!judge(board2, x+1, y-1)) {
		findmine(board1, board2, x+1, y-1,win);
	}
	if (!judge(board2, x+1, y)) {
		findmine(board1, board2, x+1, y,win);
	}
	if (!judge(board2, x+1, y+1)) {
		findmine(board1, board2, x+1, y+1,win);
	}

}

/*
������Ϸ������Ҫ���г�ʼ�����̣������ף�����ɨ�ף�ɨ�׺�չʾ���̣����ɨ����Ϣ��
*/
void game() {
	int win = 0;//win��¼�ɹ�ɨ�˼�������
	printf("��ʼ��Ϸ\n");
	char board1[ROWS][COLS] = { 0 }, board2[ROWS][COLS] = { 0 };
	initboard(board1, ROWS, COLS, '0');
	initboard(board2, ROWS, COLS, '*');
	setmine(board1, ROW, COL,count);
	printf("Ŀǰ�����̣�\n");
	//showboard(board1, ROW, COL);
	showboard(board2, ROW, COL);
	while (win<ROW*COL-count) {
		printf("������Ҫɨ�׵�����>>\n");
		int x = 0, y = 0, n;
		scanf("%d %d", &x, &y);
		if (x<1 || x > ROW || y<1 || y> COL || board2[x][y] != '*') {
			printf("����������Ϸ���λ��\n");
			continue;
		}
		n=findmine(board1,board2,x,y,&win);
		if (n) {
			printf("ɨ��ʧ�ܣ�����ը��\n");
			break;
		}
		else {
			printf("����ѡ��ɹ�\n");
		}
		showboard(board2, ROW, COL);
	}
	if(win == ROW * COL - count) printf("ȫ�����׶���ɨ������Ӯ�ˣ�\n");
}
