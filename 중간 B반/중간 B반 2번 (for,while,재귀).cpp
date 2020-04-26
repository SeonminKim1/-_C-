
#include <stdio.h> // 1~n까지 3배수 더하기
int trisum1(int n){
	int sum=0;
	int i;
	for(int i=1; i<=n; i=i++)
		if(i%3==0)	sum=sum+i;
	return sum;
}
int trisum2(int n){
	int sum1=0;
	int i=1;
	while(i<=n){ 
		if(i%3==0)
		sum1=sum1+i;
		i++;
	}
	return sum1;
}
int trisum3(int n){
	if(n<3)
		return 0;
	else if((n%3)==0) return n + trisum3(n-3);
	else return trisum3(n-1);
}
int sum(int n){
	if(n<3) return 0;
	else return sum(n-3)+trisum1(n);
}
void main()
{
	int n=100;
	int i;
	printf("(1) for trisum1(%d) = %d\n",n,trisum1(n));
	printf("(2) while trisum2(%d) = %d\n", n, trisum2(n));
	printf("(3) 재귀 trisum3(%d) = %d\n",n,trisum3(n));
	printf("(4) sum(%d)=%d\n",n,sum(n));
	//printf("(4) sum(%d)=%d\n",n,sum(n));
}