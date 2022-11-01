#include <stdio.h>
int main(){
	int n=0,L,load=0;
	int i=2,j;
	scanf("%d",&L);
	if(L==1){
	}
	else if(L==2){
		printf("2\n");
		n+=1;
	}
	else{
		printf("2\n");
		n+=1;
		while(load<L){
			for(j=2;j<i;j++){
				if(i%j==0){
					break;
				}
				else if(j!=i-1){
					continue;
				}
				else{
					load+=i;
					if(load<L){
						printf("%d\n",i);
						n++;
					}
				}
			}
			i++;
		}
	}
	printf("%d",n);
	return 0;
}
