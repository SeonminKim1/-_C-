#include <stdio.h>
void main()
{
	int i,sum=0;
	while(sum !=100)
	{
		printf("sum=%d ���� �� �Է�: ",sum);
		scanf("%d", &i);
		sum=sum+i;
	}
	printf("sum=%d",sum);
	printf("\n");
}