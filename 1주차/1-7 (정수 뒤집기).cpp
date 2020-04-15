#include <stdio.h>
int main()
{
	int x,reverse=0;
	printf("정수 x입력 : ");
	scanf("%d",&x);
	while(x!=0)
	{
		//reverse = reverse * 10;
		//reverse = reverse + x % 10;
		reverse = reverse * 10 + x % 10;
		x=x/10;
	}
	printf("합은 sum = %d\n", sum);
	printf("뒤집은수 y = %d\n",reverse);
}