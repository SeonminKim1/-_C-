#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	int i,n;
	int r;
	int count[6]={0};
	printf("주사위 횟수 : ");scanf("%d",&n);
	printf("정상 주사위 \n");
	srand(time(NULL));
	for(i=0; i<n; i++){
		r=rand()%6;
		count[r]++;
	}
	for(i=0; i<6; i++)
	{
		printf("%d : %d (%.2lf%%)\n",i+1,count[i],(double)count[i]/n*100);
	}
}