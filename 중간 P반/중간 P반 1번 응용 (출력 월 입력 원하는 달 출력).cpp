#include <stdio.h>

void main(){
	int m[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int month, startday, i;
	printf("��� ���� �Է� : ");
	scanf("%d",&month);
	startday = 1;
	for (i=0; i<month-1; i=i+1)
		startday = startday+m[i];
		startday = startday % 7;
		printf("�� �� ȭ �� �� �� ��\n");
		for (i = 0; i < startday; i++)
			printf("   ");
		for (i = 1; i <= m[month - 1]; i++){
			printf("%2d ", i);
			if ((startday + i) % 7 == 0)
				printf("\n");
		}
		printf("\n");
	}