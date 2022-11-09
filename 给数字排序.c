#include <stdio.h>
int main(){
int N;
scanf("%d",&N);
int i,j,k,m,p=0;
float sorted[N],sort[N],t,hand;
//printf("Start to input numbers that need to be sorted out.\n");
for(i=0;i<N;i++){
    scanf("%f",&sort[i]);
} 
for(i=0;i<N;i++){
//从待排列的数列中取出第i+1个进行比较 
    if(0==i){
//第一个数直接放进排列好的数列里即可 
        sorted[0]=sort[i];
    }
    else{
        for(j=0;j<i;j++){
//        	printf("at first,sorted[%d]is%f\n",j,sorted[j]);
//将取出来的数和已经排列好的数挨个比较，此时排列好的数有i个 
            if(sort[i]<sorted[j]){//进行比较 
            	p=1;
//            	printf("sort[%d](=%f)<sorted[%d](=%f)\n",i,sort[i],j,sorted[j]);
                 hand=sorted[j];
                 sorted[j]=sort[i];
//若小于第j+1个数，就先用它交换第j+1个数，手里暂时储存原来的第j+1个数 
                 if(i-1==j){
                	m=j+1;
                	sorted[m]=hand;
//                	printf("如果取出的数是小于数列里的最后一个数sorted[%d]=%f\n",m,sorted[m]);
				 }
                else{
					for(k=j+1;k<i;k++){
	//将第j+1个数后面的数依次交换往后。 
//	                    printf("开始把数往后移动j=%d k=%d\n",j,k);
						t=sorted[k];
//	                    printf(" t = %f\n",t);
	                    sorted[k]=hand;
	                    hand=t;
	//k==i-1时到达最后一次交换，此时交换完毕后把手里的数放到数列的最后 
	                }
//	                printf("hey the hand is %f\n",hand);
	                sorted[i]=hand;
//	                printf("the last number is %f\n",sorted[i]);
	            }
//                printf("Now\n");
//                for(k=0;k<i+1;k++){
//                	printf("%f ",sorted[k]);
//				}
//				printf("\nclose----------\n");
				break;
            }
            
        }
        if(p==0){//p是用来标记在前面的比较中有没有一次是成功的。 
        	sorted[i]=sort[i];
		}
    }
    p=0;//每次i改变前都进行p的重置 
}
for(i=0;i<N;i++){
    printf("%f\n",sorted[i]);
}
	return 0;
}
