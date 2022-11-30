#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/*
如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个 回文串 。
字母和数字都属于字母数字字符。
给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。
示例 1：
输入: s = "A man, a plan, a canal: Panama"
输出：true
解释："amanaplanacanalpanama" 是回文串。
示例 2：
输入：s = "race a car"
输出：false
解释："raceacar" 不是回文串。
示例 3：
输入：s = " "
输出：true
解释：在移除非字母数字字符之后，s 是一个空字符串 "" 。
由于空字符串正着反着读都一样，所以是回文串。
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