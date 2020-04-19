#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	int i,n;
	int r;
	int count[6]={0};
	printf("주사위 횟수 : ");scanf("%d",&n);
	printf("이상한 주사위 \n");
	srand(time(NULL));
	for(i=0; i<n; i++){
		r=rand()%100;
		if(r>0 && r<=10)count[0]++;
		if(r>10 && r<=20)count[1]++;
		if(r>20 && r<=30)count[2]++;
		if(r>30 && r<=40)count[3]++;
		if(r>40 && r<=50)count[4]++;
		if(r>50 && r<=100)count[5]++;
	}//r=rand()%10 if(r>50)count[5]++;else count[r]++;
	for(i=1; i<=6; i++)
	{
		printf("%d : %d (%.2lf%%)\n",i,count[i-1],(double)count[i-1]/n*100);
	}
}