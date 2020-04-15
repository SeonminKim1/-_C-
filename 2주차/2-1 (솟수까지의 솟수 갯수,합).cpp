#include <stdio.h>
int isprime(int n)
{
	int i;
	for(i=2; i<=n; i++)
	{
		if(n%i==0)break;
	}
	if(i==n) return 1;
	else return 0;
}
int main()
{
	int i,sum=0;
	int h,count=0;
	scanf("%d",&h);
	for(i=2; i<=h; i++)
	{
		if(isprime(i))//합성수는 isprime(i)==0
		{
			printf("%d ", i);
			sum=sum+i;
			count++;
		}
	}
	printf("\n");
	printf("sum=%d\n",sum);
	printf("count=%d\n",count);
}