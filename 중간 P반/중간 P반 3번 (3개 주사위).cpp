
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	int i,j;
	int ntest,star;
	int r1,r2,r3;
	int count[19]={0};
	printf("주사위 횟수 : ");scanf("%d",&ntest);
	printf("세 개 주사위 합 \n");
	srand(time(NULL));
	for(i=0; i<ntest; i++){
		r1=rand()%6+1;
		r2=rand()%6+1;
		r3=rand()%6+1;
		count[r1+r2+r3]++;
	}
	for(i=3; i<19; i++)
	{	
		printf("%2d:(%5.2lf%%) : ",i,(double)count[i]/ntest*100);
		if((double)count[i]/ntest==10.00)printf("**********\n");
		star=count[i]*100/ntest;
		for(j=0; j<star; j++)
			printf("*");
		printf("\n");
	}
}