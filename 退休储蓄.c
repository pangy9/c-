# include <stdio.h>
#include <stdlib.h>
struct _retire_info{
	int months;
	double contribution,rate_of_return;
};
typedef struct _retire_info retire_info;
int Year(int months){
	if(months % 12 == 0)
	return months/12;
	else return months/12 + 1;
}
double Balance(retire_info r,double initial,int startAge){
	double balance = initial;
	int i,j,Y,endY,startY;
	Y = Year(r.months);
	startY = startAge/12;
	endY = Year(r.months + startAge);
	for(i=startY ;i <endY;i++){
		if(i == startY){
			for(j=startAge %12 ;j<12;j++){
				balance = balance*(1 + r.rate_of_return/12) + r.contribution;
				printf("Age %3d month %2d you have $%.2lf\n",i,j,balance);
			}
		}
		else if(i != endY-1 )
		for(j=0;j<12;j++){	
			balance = balance*(1 + r.rate_of_return/12) + r.contribution;
			printf("Age %3d month %2d you have $%.2lf\n",i,j,balance);
		}
		else{
			if((startAge + r.months)%12 !=0)
			for(j=0;j<(startAge + r.months)%12;j++){
				balance = balance*(1 + r.rate_of_return/12) + r.contribution;
				printf("Age %3d month %2d you have $%.2lf\n",i,j,balance);
			}
			else
			for(j=0;j<12;j++){
				balance = balance*(1 + r.rate_of_return/12) + r.contribution;
				printf("Age %3d month %2d you have $%.2lf\n",i,j,balance);
			}
		}
	}
	return balance;
}
void retirement(int startAge,double initial,retire_info working,retire_info retired){
	double b;
	printf("Age %3d month %2d you have $%.2lf\n",startAge/12,startAge%12,initial);
	b=Balance(working,initial,startAge + 1);
	Balance(retired,b,startAge + working.months + 1);
}
int main(){
	retire_info working,retired;
	working.months = 489;
	working.rate_of_return = 0.045;
	working.contribution = 1000;
	retired.contribution = -4000;
	retired.months = 384 - 1;
	retired.rate_of_return = 0.01;
	retirement(327,21345,working,retired);
	return 0;
}
