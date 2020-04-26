#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//초단위 타이머
void main(){
	clock_t now, before, alarm_time;// , remain_msec;
	clock_t sec;
	int mm, msec, remain_msec;
	printf("알람설정(몇초후 알람) : ");
	scanf("%d", &mm);
	msec = mm  * CLOCKS_PER_SEC;
	now = before = clock();
	alarm_time = now + msec;
	while (alarm_time != now){
		do{
			now = clock();
		} while (before == now);
		before = now;
		remain_msec = alarm_time - now;
		sec = remain_msec / CLOCKS_PER_SEC;
		sec = sec % 60;
		printf("남은시간 %02d\r", sec);
	}
	printf("\n");
	printf("\a\a!!! 알람 !!!\n");
}

