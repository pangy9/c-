# include <stdio.h>
# include <stdlib.h>
# include <time.h>
int main(){
	int A,B,shu[4],shu_[4],ran,i,j,num,num0,n,jump;
	srand((unsigned int)time(NULL));
	i=0;
	do{
		shu[i] = rand()%9;//����0~9������ŵ������� 
		i=i+1;
		if(i>0){
			for(j=0;j<i;j++){//��֮ǰλ���Ƚ��Ƿ���� 
				if(shu[i]==shu[j]){ 
					i=i-1;//һ�������λ����˵�����λ������ʧЧ����������������һλ�������� 
					break;
				} 
			}			
		}	
	}while(i<4);
	do{
		printf("��������λ��");
		scanf("%d",&num);
		if(num<0 || num>9999) printf("����������ݣ�����������\n");//�ų������ͳ�����λ������ 
		else{
			A=0;
			B=0;
			for(i=0;i<4;i++){
				n = 3-i;
				shu_[n] = num%10;
				num = num/10; 
			}	
			for(i=0;i<4;i++){
				for(j=i+1;j<4;j++){
					if (shu_[i]==shu_[j]){
						printf("����������ݣ�����������\n");//����Ƿ���λ����� 
						jump = 1;//��ǣ�һ����λ�����Ҫ�����Ƚϵ�ѭ����������������� 
						break;
						}
					else jump = 0;//˵������������ѭ�� 
				}
				if(jump == 1) break;
			}
			if(jump ==0){//����������Ϊ�˱�����ĳһλ����ͬ����ʱ����ͬȴ���������A��B��ֵ 
				for(i=0;i<4;i++){
					if(shu_[i]==shu[i]){ 
						A++;//�ȶ�A�������� ������ȷλ����A+1 
						continue;
						}			
					else{
						for(j=0;j<4;j++){
							if(j==i) continue;//����֮ǰ�Ѿ��ȽϹ����� 
							else if(shu_[i]==shu[j]){//����ڲ���ȷ��λ����ȣ�B+1 
								B=B+1;
								break;
							}
						}
					}
				}
			printf("%dA%dB\n",A,B);//�ڱȽ���ɺ����A��B 
			}		
		}
	}while(A!=4);//ֻ��ÿһλ�����ֶ��¶ԲŽ��� 
		return 0;
}
