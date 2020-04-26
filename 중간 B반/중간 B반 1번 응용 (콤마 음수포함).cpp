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
		printf(",%03d", n % 1000); // 03d��� ���� �� 12005 ��� ���� 125��� �����°� ����
	}
}
//printf("%d\n",_CRT_INT_MAX); �ִ� ���ϱ� 21���� �ѰԵǸ� ���ڿ��� ����ϴ°� ����. 
void main(void) {
	int n;
	printf("���� �Է� : ");

	scanf("%d", &n);
	printcomma(n);
	printf("\n");
}