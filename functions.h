#define ROW 9
#define COL 9
#define ROWS 13
#define COLS 13
#define count 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu(void);
void game();
void initboard(char[][COLS], int, int, char);
void showboard(char[][COLS], int, int);
void setmine(char[][COLS], int, int,int);
int findmine(char[][COLS], char[][COLS], int, int,int*);
void clear(char[][COLS], char[][COLS], int, int);
int judge(char[][COLS],int, int);