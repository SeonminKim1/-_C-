#include <stdio.h>
void main()
{
	int i,sum=100;
	while(sum !=0)
	{
		printf("sum=%d –E °ª ÀÔ·Â: ",sum);
		scanf("%d", &i);
		sum=sum-i;
	}
	printf("sum=%d",sum);
	printf("\n");
}