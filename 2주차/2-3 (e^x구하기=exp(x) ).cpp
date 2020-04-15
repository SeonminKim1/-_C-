#include <stdio.h>
#include <math.h>
double myexp(int x)
{
	int i=1;;
	double term, sum, oldsum;
	oldsum=0.0;
	sum=1.0;
	term=1.0;

	for(i=1; (sum-oldsum)>0.0000001; i++)
	{
		term=term*x/i;
		oldsum=sum;
		sum=sum+term;
	}
	return sum;
}

int main()
{
	int i;
	printf("  exp() : ");
	for(i=1; i<=5; i++)
	{
		printf("%lf ", exp((double) i));
	}
		printf("\n");
		printf("myexp() : ");
	for(i=1; i<=5; i++)
	{
		printf("%lf ",myexp(i));	
	}
	printf("\n");
}