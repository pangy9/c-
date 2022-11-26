#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//为了避免溢出，输入的字符串数字长度不超6
int myatoi(const char* str) {
	//将输入的字符串的开头的数字序列转换为十进制数
	//如果是空指针或者非数字开头的默认返回-1
	//如果是有非数字阻隔的字符串，只计算开头到第一次阻断的数字
	//例如123xy3返回123,xy123返回-1
	char* p = str;
	if (str == NULL) return -1;
	if (!(*p >= 48 && *p <= 57)) return -1;
	int s = 0;
	while (*p >= 48 && *p <= 57) {
		s = s * 10 + (*p-48);
		p++;
	}
	return s;
}
long myatoiHex(const char* str) {
	//此次行为与上面的相似，但是是以16进制(字母部分只接受大写)解释。
	//如果是空指针或者非数字开头的默认返回-1
	//如果是有非数字阻隔的字符串，只计算开头到第一次阻断的数字
	//例如123xy3返回291,xy123返回-1
	char* p = str;
	if (str == NULL) return -1;
	if (!((*p >= 48 && *p <= 57) || (*p >= 65 && *p <= 70))) return -1;
	long  s = 0;
	while ((*p >= 48 && *p <= 57) || (*p >= 65 && *p <= 70)) {
		if (*p >= 48 && *p <= 57) {
			s = s * 16 + (*p - 48);
		}
		else {
			s = s * 16 + (*p - 55);
		}
		p++;
	}
	return s;
}
long mystrtol(const char* str, int base) {
	//此次行为仍然相似，但是可以自己设置2~10进制解释
	//如果是空指针或者非数字开头的默认返回-1
	//如果是有不符合格式的字符阻隔的字符串，只计算开头到第一次阻断的数字
	//例如123 2返回1
	char* p = str;
	if (str == NULL) return -1;
	int n = 47 + base;
	if (!(*p >= 48 && *p <= n)) return -1;
	long  s = 0;
	while (*p >= 48 && *p <= n) {
		s = s * base + (*p - 48);
		p++;
	}
	return s;
}