#include <stdio.h>
int perfect(int n)
{
	int i,sum=0;
	for(i=1; i<n; i++)
		if(n%i==0)
		{
			sum=sum+i;
		}
		if(sum==n)return 1;
		else return 0;
}
int main()
{
	int i,j;
	for(i=1; i<=10000; i++)
	{
		if(perfect(i))
		{
			printf("%d = 1 ",i);
			for(j=2; j<i; j++)
			{
				if(i%j==0)
					printf("+ %d ",j);
			}
			printf("\n");
		}
	}
}