#include <stdio.h>

void main(){
	int m[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int ss, month, startday, i;
		printf("1�� 1�� ���� ���� (0:�Ͽ���~6:�����) : ");
	scanf("%d", &ss);
	for (month = 1; month <= 12; month++){
		printf("****** %2d�� ******\n", month);
		startday = ss;
		for (i = 0; i < month - 1; i++)
			startday += m[i];
		startday %= 7;
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
}