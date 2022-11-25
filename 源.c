#include <stdio.h>
#include <string.h>
#include <ctype.h>
char str1[21],str2[21];
int main() {
	gets(str1);
	gets(str2);
	char* p1;
	char* p2;
	int i,t=0;
	p1 = str1;
	p2 = str2;
	while (*p1 != 0 || *p2 != 0) {
		if (*p1 > *p2) {
			t = 1;
			break;
		}
		else if (*p1 < *p2) {
			t = 2;
			break;
		}
		p1++;
		p2++;
	}
	if (t == 1) printf("%s > %s", str1, str2);
	else if (t == 2) printf("%s < %s", str1, str2);
	else printf("%s = %s", str1, str2);
	return 0;
}