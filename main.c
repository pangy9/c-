#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"
#include <stdio.h>

int main() {
	//չʾ�˵�
	int input = 0;
	do {
		menu();
		scanf("%d", &input);
		switch (input) {
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("����Ƿ�������������\n");
		}
	} while (input);
	return 0;
}