#include <stdio.h>
int main(){
	int i,x,y,s,t;
	scanf("%d %d",&x,&y);
	if(x<y){
		t=x;
		x=y;
		y=t;
	}
	s=0;
	i=y;
	while(i<=x){
		if(i%2==0){
			s=s+i;
		}
		i++;
	}
	s=-s;
	printf("%d",s);
	return 0;
}
