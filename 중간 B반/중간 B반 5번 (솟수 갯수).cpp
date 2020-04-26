#include <stdio.h> // n이 솟수면 몇번째 솟수인지 아니면 no출력
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
	int ntest;
	int h,count=0;
	scanf("%d", &ntest);
	while(ntest--){
	scanf("%d",&h);
	if(isprime(h)==1)
	{
		for(i=2; i<=h; i++)
		{
			if(isprime(i))//합성수는 isprime(i)==0
				count++;
		}
	printf("%d\n",count);
	count=0;
	}
	else if(isprime(h)==0)printf("NO\n");
}
}