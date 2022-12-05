#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/*
给定一种规律 pattern 和一个字符串 s ，判断 s 是否遵循相同的规律。

这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 s 中的每个非空单词之间存在着双向连接的对应规律。

 

示例1:

输入: pattern = "abba", s = "dog cat cat dog"
输出: true
示例 2:

输入:pattern = "abba", s = "dog cat cat fish"
输出: false
示例 3:

输入: pattern = "aaaa", s = "dog cat cat dog"
输出: false
 

提示:

1 <= pattern.length <= 300
pattern 只包含小写英文字母
1 <= s.length <= 3000
s 只包含小写英文字母和 ' '
s 不包含 任何前导或尾随对空格
s 中每个单词都被 单个空格 分隔
*/
bool isSameWord(char* s, char* t) {
	//比较s和t里面的第一个单词
	char s2[3001], t2[3001];
	strcpy(s2, s);
	strcpy(t2, t);
	char* p1 = strchr(s2, ' '), * p2 = strchr(t2, ' ');
	if (p1) *p1 = '\0';
	if (p2) *p2 = '\0';
	if (strcmp(s2, t2) == 0) return true;
	return false;
}
bool wordPattern(char* pattern, char* s) {
	int abc[26] = { 0 };
	int i = 0, j = 0, n = 1;;
	char* p1 = pattern, * p2 = s;
	//计算s的词数和pattern的字符数是否相同
	while (strchr(p2, ' ')) {
		p2 = strchr(p2, ' ');
		p2++;
		n++;
	}
	p2 = s;
	if (n != strlen(pattern)) return false;
	//对pattern从头到尾一个个查看
	while (*p1 != 0) {
		if (abc[*p1 - 'a'] == 1) {
			p1++;//p1移到下一个字符
			p2 = strchr(p2, ' ');
			if (p2 != NULL) p2++;
			continue;
		}//如果之前已经检查过那就不用再检查了
		abc[*p1 - 'a'] = 1;
		char* p = p1 + 1, * p3 = p2;
		for (;*p != 0;p++) {//看pattern中该字母的出现情况
			if (*p == *p1) {
				j = p - pattern;//计算p指向的字符在pattern中的位置
				i = 0;
				p3 = s;
				while (i < j) {
					p3 = strchr(p3, ' ');
					p3++;
					i++;
				}
				if (!isSameWord(p2, p3)) return false;
			}
			else {
				j = p - pattern;
				i = 0;
				p3 = s;
				while (i < j) {
					p3 = strchr(p3, ' ');
					p3++;
					i++;
				}
				if (isSameWord(p2, p3)) return false;
			}
		}
		p1++;
		p2 = strchr(p2, ' ');
		if (p2 != NULL) p2++;
	}
	return true;
}