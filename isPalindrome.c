#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/*
����ڽ����д�д�ַ�ת��ΪСд�ַ������Ƴ����з���ĸ�����ַ�֮�󣬶������Ŷ��ͷ��Ŷ���һ�����������Ϊ�ö�����һ�� ���Ĵ� ��
��ĸ�����ֶ�������ĸ�����ַ���
����һ���ַ��� s��������� ���Ĵ� ������ true �����򣬷��� false ��
ʾ�� 1��
����: s = "A man, a plan, a canal: Panama"
�����true
���ͣ�"amanaplanacanalpanama" �ǻ��Ĵ���
ʾ�� 2��
���룺s = "race a car"
�����false
���ͣ�"raceacar" ���ǻ��Ĵ���
ʾ�� 3��
���룺s = " "
�����true
���ͣ����Ƴ�����ĸ�����ַ�֮��s ��һ�����ַ��� "" ��
���ڿ��ַ������ŷ��Ŷ���һ���������ǻ��Ĵ���
*/
bool isPalindrome(char* s) {
    int l = strlen(s), n, j = 0;
    printf("%d\n", l);
    char a[100001];
    for (int i = 0;i < l;i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            a[j] = s[i] - 'A' + 'a';
            printf("a[%d]=%c\n",j, a[j]);
            j++;
        }
        else if ((s[i] >= 'a' && s[i] <= 'z')||(s[i]>='0'&& s[i]<='9') ){
            a[j] = s[i];
            printf("a[%d]=%c\n", j, a[j]);
            j++;
        }
    }
    a[j] ='\0';
    printf("%s\n", a);
    l = strlen(a);
    n = l / 2;
    printf("l=%d,n=%d\n", l, n);
    for (int i = 0;i <= n;i++) {
        if (a[i] != a[l - 1 - i]) return false;
    }
    return true;
}