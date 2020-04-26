
#include <stdio.h> // 1~n까지 4배수 더하기
int quadsum1(int n){
	int sum=0;
	int i;
	for(int i=1; i<=n; i=i++)
		if(i%4==0)	sum=sum+i;
	return sum;
}
int quadsum2(int n){
	int sum1=0;
	int i=1;
	while(i<=n){ 
		if(i%4==0)
		sum1=sum1+i;
		i++;
	}
	return sum1;
}
int quadsum3(int n){
	if(n<4)
		return 0;
	else if((n%4)==0) return n + quadsum3(n-4);
	else return quadsum3(n-1);
}
int sum(int n){
	if(n<4) return 0;
	else return sum(n-4)+quadsum1(n);
}
void main()
{
	int n=100;
	int i;
	printf("(1) for quadsum1(%d) = %d\n",n,quadsum1(n));
	printf("(2) while quadsum2(%d) = %d\n", n, quadsum2(n));
	printf("(3) 재귀 quadsum3(%d) = %d\n",n,quadsum3(n));
	printf("(4) sum(%d)=%d\n",n,sum(n));
	//printf("(4) sum(%d)=%d\n",n,sum(n));
}