#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
来自leecode第26题，编写一函数来原地删除传入的数组中重复的元素，
传入的数组是已经进行升序排列的数组。
函数要返回删除重复项中剩余的元素的个数k
要求把删除多余元素后剩余的元素都按顺序放在数组的前k项中
不使用额外的空间
提示：
1 <= nums.length <= 3 * 10^4
-10^4 <= nums[i] <= 10^4
nums 已按 升序 排列
*/
int removeDuplicates(int* nums, int numsSize) {
	int k=0,m=0,j=1;//j代表p1和p21的距离
	int* p1 = nums, * p2 = p1 + j;
	int min = nums[0];
	//找到第一个第一次出现的数，p1指向它
	for (int i = 0;i < numsSize - 1;i++) {
		if (*p1 == *p2) {
			*p2 = min;
			p2++;
			m++;//m标记删除的个数
		//如果*p2跟*p1的数是一样，就是重复了
		//那就改变值为最小值，相当于删除，p2继续移动
		}
		else {
		//如果*p2和*p1的值不一样，那就更新p1的位置，指向下一个第一次出现的数
			p1 = nums + i + 1;
			p2++;
		//p2仍然继续移动
		}
		
	}
	k = numsSize - m;//想要得到的数组的元素个数
	p1 = nums + 1;
	p2 = p1 + j;
	for (int i = 1;i < k;i++) {
		if (*p1 <= *(p1 - 1)) {
			p2 = p1 + j;
			while (*p2 == min) {
				p2++;
				j++;//每跳过一个删除的元素，p1和p2的距离就大一格
			}
			*p1 = *p2;
			p1++;
		}
		else p1++;
	}
	return k;
}