#include <stdio.h>
int main(){
	int n,x,x1,i,sum;
	n=0;
	sum=0;
	scanf("%d",&x);
	x1 = x;
	while(x != 0){
		if(x%2 == 1){
			n++;
			x = x/2;
		}
		else{
			x = x/2;
		}
	} 
	while(x1 != 0){
		sum = sum + (x1 % 10);
		x1 = x1 / 10;
	}
	printf("%d\n%d",n,sum);
	return 0;
} 
