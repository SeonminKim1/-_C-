#pragma warning (disable:4996)
#include <stdio.h>
#include <time.h>

//타이머 입력, 시간경과후 종료
void main(void){
	clock_t now, before, alarm_time;// , remain_msec;
	clock_t sec, min, hour, milsec;
	int mm, ss, msec, remain_msec;

	printf("타이머 몇분: ");
	scanf("%d", &mm);
	printf("       몇초: ");
	scanf("%d", &ss);
	ss += mm * 60;
	msec = ss * CLOCKS_PER_SEC;
	now = before = clock();
	alarm_time = now + msec;
	while (alarm_time != now){
		do{
			now = clock();
		} while (before == now);
		before = now;
		remain_msec = alarm_time - now;
		sec = remain_msec / CLOCKS_PER_SEC;
		milsec = remain_msec % CLOCKS_PER_SEC;
		hour = sec / 3600;
		min = (sec / 60) % 60;
		sec = sec % 60;
		printf("%d:%02d:%02d.%03d \r", hour, min, sec, milsec);
	}
}