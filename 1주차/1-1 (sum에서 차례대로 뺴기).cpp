#include <stdio.h>
void main()
{
	int i,sum=100;
	while(sum !=0)
	{
		printf("sum=%d �E �� �Է�: ",sum);
		scanf("%d", &i);
		sum=sum-i;
	}
	printf("sum=%d",sum);
	printf("\n");
}