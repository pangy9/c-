#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
/*
给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。
示例 1：
输入:a = "11", b = "1"
输出："100"
示例 2：
输入：a = "1010", b = "1011"
输出："10101"
提示：
1 <= a.length, b.length <= 104
a 和 b 仅由字符 '0' 或 '1' 组成
字符串如果不是 "0" ，就不含前导零
*/
char* addBinary(char* a, char* b) {
    if (a[0] == '0' && b[0] == '0') {//如果都是0就直接输出0不用计算了
        char* s = "0";
        return s;
    }
    int al = strlen(a), bl = strlen(b);
    int len = al > bl ? al : bl;
    static char str[10002];
    str[len + 1] = '\0';//让它成为一个字符串
    str[len] = '0';
    for (int j = len;j > 0;j--) {//从末尾开始计算
        char s2 = '0';
        str[j - 1] = '0';
        if (al>0 && bl>0) {
            s2 = str[j] + a[al-1] + b[bl-1] - 96;
        }
        else if (al>0 || bl>0) {
            if (al > 0) {
                s2 = str[j] + a[al-1] - '0';
            }
            else {
                s2 = str[j] + b[bl-1] - '0';
            }
        }
        if (s2 >= 2 + '0') {
            str[j] =s2-2 ;//要是刚好为2就是0，要是为3就给1
            str[j - 1]++;
        }
        else str[j] = s2;
        al--;
        bl--;
    }
    if (str[0] != '0') return str;
    else {
        char* s = str;//要是开头不是'0'，就把'0'给覆盖掉
        s++;
        strcpy(str, s);
        return str;
    }
}