#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
char str1[101], str2[101],sum[102];
int main() {
	scanf("%s %s", str1, str2);
	int n1, n2,n,s=0,add=0,a,b,i,j;
	n1 = strlen(str1);
	n2 = strlen(str2);
	n =1+( n1 > n2 ? n1 : n2);
	//结果的最大位数是加数最大位数加一
	for (i = 0;i < n;i++) {
		sum[i] = '0';
	}//都填0
	for (i = n - 1,j=0;i >= 0;i--,j++) {
		//倒着相加，从第n+1位一直加到第1位的加法
		if (j >= n1 && j >= n2) {
			a = 0;
			b = 0;
		}
		else if (j >= n1) {
			a = 0;//把字符转换为int
			b = str2[n2 - j-1]-48;
		}
		else if (j >= n2) {
			a = str1[n1 - j-1]-48;
			b = 0;
		}
		else {
			a = str1[n1 - j-1]-48;
			b = str2[n2 - j-1]-48;
		}
		//printf("i=%d,j=%d,a=%d,b=%d\n", i,j, a, b);
		s = a + b+add;
		if (s >= 10) {
			sum[i] = s % 10+48;//再把int转回字符
			//printf("i=%d ,%c\n", i, sum[i]);
			add = 1;
		}
		else{
			sum[i] = s+48;
			//printf("i=%d ,%c\n", i, sum[i]);
			add = 0;
		}
	}
	i = 0;
	if (sum[i] == '0') i++;
	for (i;i < n;i++) {
		printf("%c", sum[i]);
	}
	return 0;
}