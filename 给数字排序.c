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
//�Ӵ����е�������ȡ����i+1�����бȽ� 
    if(0==i){
//��һ����ֱ�ӷŽ����кõ������Ｔ�� 
        sorted[0]=sort[i];
    }
    else{
        for(j=0;j<i;j++){
//        	printf("at first,sorted[%d]is%f\n",j,sorted[j]);
//��ȡ�����������Ѿ����кõ��������Ƚϣ���ʱ���кõ�����i�� 
            if(sort[i]<sorted[j]){//���бȽ� 
            	p=1;
//            	printf("sort[%d](=%f)<sorted[%d](=%f)\n",i,sort[i],j,sorted[j]);
                 hand=sorted[j];
                 sorted[j]=sort[i];
//��С�ڵ�j+1��������������������j+1������������ʱ����ԭ���ĵ�j+1���� 
                 if(i-1==j){
                	m=j+1;
                	sorted[m]=hand;
//                	printf("���ȡ��������С������������һ����sorted[%d]=%f\n",m,sorted[m]);
				 }
                else{
					for(k=j+1;k<i;k++){
	//����j+1��������������ν������� 
//	                    printf("��ʼ���������ƶ�j=%d k=%d\n",j,k);
						t=sorted[k];
//	                    printf(" t = %f\n",t);
	                    sorted[k]=hand;
	                    hand=t;
	//k==i-1ʱ�������һ�ν�������ʱ������Ϻ����������ŵ����е���� 
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
        if(p==0){//p�����������ǰ��ıȽ�����û��һ���ǳɹ��ġ� 
        	sorted[i]=sort[i];
		}
    }
    p=0;//ÿ��i�ı�ǰ������p������ 
}
for(i=0;i<N;i++){
    printf("%f\n",sorted[i]);
}
	return 0;
}
