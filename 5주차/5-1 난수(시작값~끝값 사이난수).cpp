#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
int n,first,end,r;
int i;
int sum=0;
printf("������ ����: ");scanf("%d",&n);
printf("���۰� �� : ");scanf("%d %d",&first,&end);
srand(time(NULL));
for(i=0; i<n; i++)
{
	r=rand()%(end-first+1);
	r=first+r;
	printf("%d ",r);
	sum=sum+r;
}
printf("\n");
printf("sum=%d avg=%lf\n",sum,(double)sum/n);
}