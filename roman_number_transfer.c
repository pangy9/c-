#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
/*
来自leecode第13题，数据都是有效的罗马数字，符合罗马数字的书写规范
表示的整数再[1,3999]内
*/
int romanToInt(char* s) {
	int n = strlen(s);
	char* p = s;
	int sum = 0,a=0,num[4000],i=0;
	do {
		switch (*p) {
            case 'I':
                a = 1;
                break;
            case 'V':
                a = 5;
                break;
            case 'X':
                a = 10;
                break;
            case 'L':
                a = 50;
                break;
            case 'C':
                a = 100;
                break;
            case 'D':
                a = 500;
                break;
            case 'M':
                a = 1000;
                break;
		}
        num[i] = a;
        i++;
        p++;
	} while (*p != '\0');
    for (i = 0;i < n;i++) {
        if (i == n - 1) {
            sum = sum + num[i];
        }
        else if (num[i] >= num[i + 1]) {
            sum = sum + num[i];
        }
        else {
            sum = sum + num[i + 1] - num[i];
            i++;
        }
    }
    return sum;
}