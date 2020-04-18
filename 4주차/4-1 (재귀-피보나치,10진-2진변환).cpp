#include <stdio.h>
int sum(int n)
{
	if(n<=1)
		return n;
	else 
		return n+sum(n-1);
}

int factorial(int n)
{
	if(n<=1)
		return 1;
	else 
		return n*factorial(n-1);
}

int fibo(int n)
{
	if(n<=1)
		return n;
	else 
		return fibo(n-1) + fibo(n-2);
}

void binary(int n)
{
	if(n<2)
		printf("%d",n);
	else 
	{
		binary(n/2);
		printf("%d",n%2);
	}
}
void main()
{
	int i, n = 10;
	printf("sum(%d) = %d\n", n, sum(n));
	printf("factorial(%d) = %d\n", n, factorial(n));
	printf("fibonacci = ");
	for (i=0;i<=30;i++)
		printf("%d ",fibo(i));
	printf("\n");
	n = 12345;
	printf("binary(%d) = ", n);
	binary(n);
	printf("\n");
}