#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
/*
����leecode��14�⣬��дһ�������������ַ��������е������ǰ׺��
�ַ�������СдӢ����ĸ���
��������ڹ���ǰ׺�ͷ��ؿ��ַ�������
*/
char* longestCommonPrefix(char** strs, int strsSize) {
	static char p[201];
	int t = 0, n = 0;
	int l = strlen(strs[0]);
	//t������Ƕ��break,n�����ƶ�ָ��
	p[0] = strs[0][0];
	for (int i = 0;i < l;i++) {
		for (int j = 0;j < strsSize;j++) {
			if (strs[0][i] != strs[j][i]) {
				t = 1;
				break;
			}
		}
		if (t == 1) break;
		else {
			p[n] = strs[0][i];
			n++;
		}
	}
	if (n == 0) {
		p[0] = '\0';//�����ַ���ֹ
		return p;
	}
	else {
		p[n] = '\0';//����'\0'ʹ���Ϊ�ַ���
		return p;
	}
}