#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"
#include <stdio.h>

int main() {
	//展示菜单
	int input = 0;
	do {
		menu();
		scanf("%d", &input);
		switch (input) {
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入非法，请重新输入\n");
		}
	} while (input);
	return 0;
}