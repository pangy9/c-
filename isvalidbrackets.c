#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/*
* 来自力扣第20题
* 给定一个只包括 '('，')'，'{'，'}'，'['，']'?的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。
提示：
1 <= s.length <= 104
s 仅由括号 '()[]{}' 组成
*/
bool isValid(char* s) {
    short temp = 0;
    char * p1 = s;
    short p2[5000] = {'0'};
	int i = 0;
    //i记录目前的连续左括号有多少个，来对应于要有多少个右括号
	while (*p1 != '\0') {
        switch (*p1) {
        case '(':
            temp = 1;
            break;
        case ')':
            temp = 4;
            break;
        case '[':
            temp = 2;
            break;
        case ']':
            temp = 8;
            break;
        case '{':
            temp = 3;
            break;
        case '}':
            temp = 12;
            break;
        }
        if (temp%4!=0 ) {
            //如果是左括号开头就用p2进行记忆对应后面应该要出现什么右括号
            p2[i] = temp;
            i++;
        }
        else {
            //进入则说明是右括号模式
            if (i <= 0) return false;//i应该>=0才进入右括号模式
            i--; 
            if (p2[i] * 4 != temp) return false;
            //如果之中有哪个不对应，就false
        }
        p1++;
	}
    if (i != 0) return false;//如果左右括号不对应的话 i！=0
    else return true;
}