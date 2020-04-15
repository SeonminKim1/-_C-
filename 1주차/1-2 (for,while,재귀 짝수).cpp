#include <stdio.h>
int evensum1(int n);
int evensum2(int n);
int evensum3(int n);

//evensum
void main(){
	int n = 100;
	int SUM = 0;
	int i;
	printf("(1) for evensum1 (%d) = %d\n", n, evensum1(n));
	printf("(2) while evensum2 (%d) = %d\n", n, evensum2(n));
	printf("(3) 재귀  evensum3 (%d) = %d\n", n, evensum3(n));
	//sum 을 구한다
	for (i = 0; i <= n; i += 2)
		SUM += evensum1(i);
	printf("(4) SUM = %d \n", SUM);

}

int evensum1(int n){
	int i, sum = 0;
	for (i = 0; i <= n; i += 2)
		sum += i;
	return sum;

}
int evensum2(int n){
	int i = 0, sum = 0;
	while (i <= n){
		sum += i;
		i += 2;
	}
	return sum;
}
int evensum3(int n){
	int sum;
	if ((n % 2) == 1)
		n -= 1;
	if (n <= 1)
		return n;
	sum = n + evensum3(n - 2);
	return sum;

}