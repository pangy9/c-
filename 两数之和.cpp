/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 # include<stdio.h>
 # include<stdlib.h>
int* twoSum(int* nums, int numsSize, int target){
    int jump=0,i,j;
    for(i=0;i<numsSize;i++){
        for(j=i+1;j<numsSize;j++){
            if((nums[i]+nums[j])==target){
                printf("[%d,%d]",i,j);
                jump=1;
                break;
            }
            if(jump == 1) break;
        }
    }
}
int main(){
    int numsSize,target,i=0;
    int* nums;
    int* twoSum(int*,int,int);
    printf("ÇëÊäÈëÊý×énums = {...}, target = ...\n");
	scanf("nums = {");
    do{
    	scanf("%d",&nums[i]);
    	i ++;
	}while(i!='}');
    scanf(", target = %d",&target);
    numsSize = sizeof(nums)/sizeof(nums)[0];
    twoSum(nums,numsSize,target);
    return 0;
}
