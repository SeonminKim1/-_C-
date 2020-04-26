#include <stdio.h>
void printcomma(int n) {
	if (n<0) {
		printf("-");
		n = -n;
		printcomma(n);
	}
	else if (n < 1000 && n >= 0)
		printf("%d", n);
	else {
		printcomma(n / 1000);
		printf(",%03d", n % 1000); // 03d라고 쓰는 건 12005 라고 쓰면 125라고 나오는거 방지
	}
}
//printf("%d\n",_CRT_INT_MAX); 최댓값 구하기 21억이 넘게되면 문자열로 계산하는게 보통. 
void main(void) {
	int n;
	printf("정수 입력 : ");

	scanf("%d", &n);
	printcomma(n);
	printf("\n");
}