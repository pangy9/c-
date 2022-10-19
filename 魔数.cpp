# include <stdio.h>
# include <stdlib.h>
# include <time.h>
int main(){
	int A,B,shu[4],shu_[4],ran,i,j,num,num0,n,jump;
	srand((unsigned int)time(NULL));
	i=0;
	do{
		shu[i] = rand()%9;//生成0~9的数存放到数组里 
		i=i+1;
		if(i>0){
			for(j=0;j<i;j++){//与之前位数比较是否相等 
				if(shu[i]==shu[j]){ 
					i=i-1;//一旦有相等位数就说明这个位数生成失效，重来继续生成这一位数的数字 
					break;
				} 
			}			
		}	
	}while(i<4);
	do{
		printf("请输入四位数");
		scanf("%d",&num);
		if(num<0 || num>9999) printf("输入错误数据，请重新输入\n");//排除负数和超过四位数的数 
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
						printf("输入错误数据，请重新输入\n");//检查是否有位数相等 
						jump = 1;//标记，一旦有位数相等要跳出比较的循环，避免多次输出文字 
						break;
						}
					else jump = 0;//说明不用跳出大循环 
				}
				if(jump == 1) break;
			}
			if(jump ==0){//设置条件是为了避免检查某一位上相同数字时有相同却还是输出了A和B的值 
				for(i=0;i<4;i++){
					if(shu_[i]==shu[i]){ 
						A++;//先对A的数讨论 ，在正确位置则A+1 
						continue;
						}			
					else{
						for(j=0;j<4;j++){
							if(j==i) continue;//跳过之前已经比较过的数 
							else if(shu_[i]==shu[j]){//如果在不正确的位置相等，B+1 
								B=B+1;
								break;
							}
						}
					}
				}
			printf("%dA%dB\n",A,B);//在比较完成后输出A和B 
			}		
		}
	}while(A!=4);//只有每一位上数字都猜对才结束 
		return 0;
}
