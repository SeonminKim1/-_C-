#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning (disable:4996)
//�ʴ��� Ÿ�̸�
void main() {
	int alarm_time;
	int seconds;
	printf("�˶�����(������ �˶�) : ");
	scanf("%d", &seconds);

	while (seconds != 0) {
		printf("%d�� �� �˶�\n", seconds);
		alarm_time = clock() + CLOCKS_PER_SEC; // CLOCKS_PER_SEC �� 1�ʿ� 1000�� Ŭ���Ѵٴ� ��.
		while (alarm_time != clock()) {} // alarm_time-clock() > 0  // clock()-alarm_time < 0  
 		seconds--;
	}
	printf("\n!!!! �˶� !!!! \n\n");
}

// 1�ʿ� 1000Ŭ�� �����̴µ�. 
// 1���Ŀ� Ŭ���� alarm_time �� ����ٰ�
// �׷��� while�� ���ٰ� alarm_time�̶� ���� �ð��̶�(clock()) ������ �׶� ������.