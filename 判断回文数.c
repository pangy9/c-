#include <stdio.h>
int main(){
	int n,a,i,b;
	int shu[100];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&shu[i]);
	}
	for(i=0;i<n;i++){
		if(shu[i]/10==0){
			printf("Yes\n");
		}
		else{
			int cun[9];
			a = shu[i];
			int j,t;
			t=j=0;
			while(a!=0){
				cun[j]=a%10;
				a=a/10;
				j++;
			}
			for(b=0;b<=(j-1)/2;b++){
				if(cun[b]!=cun[j-b-1]){
				printf("No\n");
				t=1;
				break;
				}
			}if(t==0)printf("Yes\n");
		}	
	}
	return 0;
}
