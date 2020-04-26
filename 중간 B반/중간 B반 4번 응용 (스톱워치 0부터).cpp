#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	clock_t start, now, duration;
	int h,m,s,msec;
	int i,j,k=0;
	start=clock();
	while(1)
	{
		now=clock();
		duration=now-start;
		s=duration /CLOCKS_PER_SEC;
		msec=duration % CLOCKS_PER_SEC;
		h=s/3600;
		m=(s-h*3600)/60;
		s=(s-h*3600-m*60);
		printf("%d:%d:%d:%d\r",h,m,s,msec);
	}
}