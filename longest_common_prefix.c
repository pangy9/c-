#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
/*
来自leecode第14题，编写一个函数来查找字符串数组中的最长公共前缀。
字符串仅由小写英文字母组成
如果不存在公共前缀就返回空字符串“”
*/
char* longestCommonPrefix(char** strs, int strsSize) {
	static char p[201];
	int t = 0, n = 0;
	int l = strlen(strs[0]);
	//t用来标记多次break,n用来移动指针
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
		p[0] = '\0';//填上字符终止
		return p;
	}
	else {
		p[n] = '\0';//填上'\0'使其成为字符串
		return p;
	}
}