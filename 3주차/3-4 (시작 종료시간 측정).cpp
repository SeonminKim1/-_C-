#include <stdio.h>
#include <time.h>
void main()
{
	time_t now;
	time(&now);
	clock_t start, finish,start1,finish1;
	int i,j,k=0;
	double duration, duration1;
	printf("시작 : %s",ctime(&now));
	start=clock();
	for(i=1; i<=10000; i++)
		for(j=1; j<=20000; j++)
			k++;
	finish=clock();
	duration=(double)(finish-start)/CLOCKS_PER_SEC;
	time(&now);
	printf("종료 : %s",ctime(&now));
	printf("실행시간 = %lf 초입니다.\n",duration);
	printf("\n");
	time(&now);
	struct tm *tp;
	tp=localtime(&now);
	printf("시작 : %d:%d:%d\n",tp->tm_hour,tp->tm_min,tp->tm_sec);
	start1=clock();
	for(i=1; i<=10000; i++)
		for(j=1; j<=20000; j++)
			k++;
	finish1=clock();
	duration1= (double)(finish1-start1)/CLOCKS_PER_SEC;
	time(&now);
	tp=localtime(&now);
	printf("종료 : %d:%d:%d\n",tp->tm_hour,tp->tm_min,tp->tm_sec);
	printf("실행시간 : %lf\n",duration1);
}