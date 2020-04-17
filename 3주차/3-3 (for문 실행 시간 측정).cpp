#include <stdio.h>
#include <time.h>
void main()
{
	clock_t start,finish;
	double duration;
	int i,j,k=0;
	start=clock();
	for(i=1; i<=10000; i++)
	{
		for(j=1; j<=10000; j++)
			k++;
	}
	finish=clock();
	duration = (double)(finish-start)/CLOCKS_PER_SEC;
	printf("%f초 입니다.\n",duration);
}