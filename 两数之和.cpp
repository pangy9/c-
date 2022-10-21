#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i,j,sum;
    int* ret;
    for(i = 0;i < numsSize;i++){
        for(j = i + 1;j < numsSize;j++){
            sum = nums[i] + nums[j];
            if(sum == target){
                ret = malloc(sizeof(int)*2);
                ret[0]=i;
                ret[1]=j; 
               *returnSize = 2;
                return ret;
            }
        }
    }
    *returnSize = 0;
    free (ret);
    return NULL;
}
