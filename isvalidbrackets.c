#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/*
* �������۵�20��
* ����һ��ֻ���� '('��')'��'{'��'}'��'['��']'?���ַ��� s ���ж��ַ����Ƿ���Ч��

��Ч�ַ��������㣺

�����ű�������ͬ���͵������űպϡ�
�����ű�������ȷ��˳��պϡ�
ÿ�������Ŷ���һ����Ӧ����ͬ���͵������š�
��ʾ��
1 <= s.length <= 104
s �������� '()[]{}' ���
*/
bool isValid(char* s) {
    short temp = 0;
    char * p1 = s;
    short p2[5000] = {'0'};
	int i = 0;
    //i��¼Ŀǰ�������������ж��ٸ�������Ӧ��Ҫ�ж��ٸ�������
	while (*p1 != '\0') {
        switch (*p1) {
        case '(':
            temp = 1;
            break;
        case ')':
            temp = 4;
            break;
        case '[':
            temp = 2;
            break;
        case ']':
            temp = 8;
            break;
        case '{':
            temp = 3;
            break;
        case '}':
            temp = 12;
            break;
        }
        if (temp%4!=0 ) {
            //����������ſ�ͷ����p2���м����Ӧ����Ӧ��Ҫ����ʲô������
            p2[i] = temp;
            i++;
        }
        else {
            //������˵����������ģʽ
            if (i <= 0) return false;//iӦ��>=0�Ž���������ģʽ
            i--; 
            if (p2[i] * 4 != temp) return false;
            //���֮�����ĸ�����Ӧ����false
        }
        p1++;
	}
    if (i != 0) return false;//����������Ų���Ӧ�Ļ� i��=0
    else return true;
}