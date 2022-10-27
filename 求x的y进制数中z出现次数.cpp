#include <stdio.h>
int main(){
	int x,y,z,shu[9],i=0,j,n=0;
	scanf("%d %d %d",&x,&y,&z);
	while(x!=0){
		shu[i]=x%y;//虽然是倒序但是没关系 
		x=x/y;
		i++;
	}
	for(j=0;j<i;j++){
		if(shu[j]==z) n++; 
	}
	printf("%d",n);
	return 0;
}
