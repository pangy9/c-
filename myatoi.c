#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//Ϊ�˱��������������ַ������ֳ��Ȳ���6
int myatoi(const char* str) {
	//��������ַ����Ŀ�ͷ����������ת��Ϊʮ������
	//����ǿ�ָ����߷����ֿ�ͷ��Ĭ�Ϸ���-1
	//������з�����������ַ�����ֻ���㿪ͷ����һ����ϵ�����
	//����123xy3����123,xy123����-1
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
	//�˴���Ϊ����������ƣ���������16����(��ĸ����ֻ���ܴ�д)���͡�
	//����ǿ�ָ����߷����ֿ�ͷ��Ĭ�Ϸ���-1
	//������з�����������ַ�����ֻ���㿪ͷ����һ����ϵ�����
	//����123xy3����291,xy123����-1
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
	//�˴���Ϊ��Ȼ���ƣ����ǿ����Լ�����2~10���ƽ���
	//����ǿ�ָ����߷����ֿ�ͷ��Ĭ�Ϸ���-1
	//������в����ϸ�ʽ���ַ�������ַ�����ֻ���㿪ͷ����һ����ϵ�����
	//����123 2����1
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