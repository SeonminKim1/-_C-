#include <stdio.h>
int main()
{
	int x,reverse=0;
	printf("���� x�Է� : ");
	scanf("%d",&x);
	while(x!=0)
	{
		//reverse = reverse * 10;
		//reverse = reverse + x % 10;
		reverse = reverse * 10 + x % 10;
		x=x/10;
	}
	printf("���� sum = %d\n", sum);
	printf("�������� y = %d\n",reverse);
}