#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void spiralOrder(int** matrix, int m, int n) {
	int i, j, c, d, e, t = 0, k;
	c = m;
	d = n;
	k = 0;
	while (!(c == 0 || d == 0)) {
		if (k % 2 == 0) {
			c--;
			k++;
			if (c == 0) {
				t = 1;
				break;
			}
		}
		else {
			d--;
			k++;
			if (d == 0) {
				t = 2;
				break;
			}
		}
	}
	if (k % 4 == 0) {
		if (t == 1) {
			c = m - 1 - k / 4;
			d = k / 4;
		}
		else {
			d = n - 1 - k / 4;
			c = k / 4;
		}
	}
	else if (k % 4 == 1) {
		if (t == 1) {
			c = k / 4;
			d = n - 1 - k / 4;
		}
		else {
			d = m - 1 - k / 4;
			c = k / 4;
		}
	}
	else if (k % 4 == 2) {
		if (t == 1) {
			d = n - 1 - k / 4;
			c = k / 4;
		}
		else {
			d = k / 4;
			c = m - 1 - k / 4;
		}
	}
	else if (k % 4 == 3) {
		if (t == 1) {
			c = k / 4 + 1;
			d = k / 4;
		}
		else {
			d = k / 4 + 1;
			c = k / 4;
		}
	}
	e = 0;
	i = j = 0;
	t = 0;
	//printf("[%d][%d]\n", c, d);
	while (1) {//j代表行的变化，i代表列的变化
		for (i = e;i < n - e;i++) {
			printf("%d ", matrix[e][i]);
			if (e == c && i == d) {
				t = 1;
				//printf("[%d][%d]\n", j, i);
				break;
			}
		}
		if (t == 1) break;
		for (j = e + 1;j < m - e;j++) {
			printf("%d ", matrix[j][n - e - 1]);
			if (j == c && (n - e - 1) == d) {
				//printf("[%d][%d]\n", j, i);
				t = 1;
				break;
			}
		}
		if (t == 1) break;
		for (i = n - 2 - e;i > e - 1;i--) {
			printf("%d ", matrix[m - e - 1][i]);
			if ((m - e - 1) == c && i == d) {
				//printf("[%d][%d]\n", j, i);
				t = 1;
				break;
			}
		}
		if (t == 1) break;
		for (j = m - 2 - e;j > e;j--) {
			printf("%d ", matrix[j][e]);
			if (j == c && e == d) {
				//printf("[%d][%d]\n", j, i);
				t = 1;
				break;
			}
		}
		if (t == 1) break;
		e++;
	}
	printf("\n");
}
