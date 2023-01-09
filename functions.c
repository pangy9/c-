#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"

void menu() {
	printf("****************************************\n");
	printf("**************请输入选项****************\n");
	printf("****1.开始游戏            0.退出游戏****\n");
	printf("****************************************\n");
}

/*
将对应的棋盘全部初始化为传入的值
*/
void initboard(char board[ROWS][COLS], int row, int col, char set) {
	for (int i = 0;i < row;i++) {
		for (int j = 0;j < col;j++) {
			board[i][j] = set;
		}
	}
}

/*
展示该棋盘
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
布置雷
*/
void setmine(char board[ROWS][COLS], int row, int col,int cnt) {
	int x = 0, y = 0;
	srand((unsigned int)time(0));
	while (cnt) {
		x = rand() % 9 + 1;//要产生1-9的数
		y = rand() % 9 + 1;
		if (board[x][y]=='0') {
			board[x][y] = '1';
			cnt--;
		}
	}
}

int findmine(char board1[ROWS][COLS], char board2[ROWS][COLS], int x, int y,int* win) {
	if (board1[x][y] == '1') return 1;//踩雷
	else  board2[x][y] = board1[x - 1][y - 1] + board1[x - 1][y] + board1[x - 1][y + 1]
		+ board1[x][y - 1] + board1[x][y + 1] + board1[x + 1][y - 1] + board1[x + 1][y]
		+ board1[x + 1][y + 1]  - 7 * '0';
	if(board2[x][y]=='0') clear(board1,board2, x, y,win);
	(*win)++;
		return 0;
}

/*
判断是否在界外或者已经清空,是就返回1，不是返回0
*/
int judge(char board[][COLS],int x, int y) {
	if (x<1 || x > ROW || y<1 || y> COL) return 1;
	if (board[x][y] != '*') return 1;
	return 0;
}

/*
进行大面积清空
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
主体游戏函数，要进行初始化棋盘，放置雷，进行扫雷，扫雷后展示棋盘，输出扫雷信息等
*/
void game() {
	int win = 0;//win记录成功扫了几个格子
	printf("开始游戏\n");
	char board1[ROWS][COLS] = { 0 }, board2[ROWS][COLS] = { 0 };
	initboard(board1, ROWS, COLS, '0');
	initboard(board2, ROWS, COLS, '*');
	setmine(board1, ROW, COL,count);
	printf("目前的棋盘：\n");
	//showboard(board1, ROW, COL);
	showboard(board2, ROW, COL);
	while (win<ROW*COL-count) {
		printf("输入你要扫雷的坐标>>\n");
		int x = 0, y = 0, n;
		scanf("%d %d", &x, &y);
		if (x<1 || x > ROW || y<1 || y> COL || board2[x][y] != '*') {
			printf("请重新输入合法的位置\n");
			continue;
		}
		n=findmine(board1,board2,x,y,&win);
		if (n) {
			printf("扫雷失败，被雷炸死\n");
			break;
		}
		else {
			printf("本次选择成功\n");
		}
		showboard(board2, ROW, COL);
	}
	if(win == ROW * COL - count) printf("全部的雷都已扫出，你赢了！\n");
}
