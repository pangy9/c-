#include <stdio.h>
int gcd(int a,int b){
    if(a<b){
        int t=b;
        b=a;
        a=t;
    }
    if(a==b) return a;
    else return gcd(b,a-b);
}
int main(){
	int x,y;
	scanf("%d %d",&x,&y);
	printf("x 和 y 的最大公约数是%d",gcd(x,y));
	return 0;
} 
