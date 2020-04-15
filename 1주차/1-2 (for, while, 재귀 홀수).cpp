#include <stdio.h> // 1~n±îÁö È¦¼ö ´õÇÏ±â
int oddsum1(int n){
	int sum=0;
	int i;
	for(int i=1; i<=n; i=i++)
		if(i%2==1)	sum=sum+i;
	return sum;
}
int oddsum2(int n){
	int sum1=0;
	int i=1;
	while(i<=n){ 
		if(i%2==1)
		sum1=sum1+i;
		i++;
	}
	return sum1;
}
int oddsum3(int n){
	if(n<1)
		return 0;
	else if((n%2)==1) return n + oddsum3(n-2);
	else return oddsum3(n-1);
}

/*int sum(int n){
	if(n<1) return 0;
	else return sum(n-2)+oddsum1(n);
}*/
void main()
{
	int n=100;
	int sum=0;
	int i;
	printf("(1) for oddsum1(%d) = %d\n",n,oddsum1(n));
	printf("(2) while oddsum2(%d) = %d\n", n, oddsum2(n));
	printf("(3) Àç±Í oddsum3(%d) = %d\n",n,oddsum3(n));
	for(i=1; i<=100; i=i+2)
		sum=sum+oddsum1(i);
		printf("(4) sum=%d\n",sum);
	//printf("(4) sum(%d)=%d\n",n,sum(n));
}