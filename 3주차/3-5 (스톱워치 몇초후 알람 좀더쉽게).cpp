#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning (disable:4996)
//초단위 타이머
void main() {
	int alarm_time;
	int seconds;
	printf("알람설정(몇초후 알람) : ");
	scanf("%d", &seconds);

	while (seconds != 0) {
		printf("%d초 후 알람\n", seconds);
		alarm_time = clock() + CLOCKS_PER_SEC; // CLOCKS_PER_SEC 는 1초에 1000번 클록한다는 뜻.
		while (alarm_time != clock()) {} // alarm_time-clock() > 0  // clock()-alarm_time < 0  
 		seconds--;
	}
	printf("\n!!!! 알람 !!!! \n\n");
}

// 1초에 1000클록 움직이는데. 
// 1초후에 클록을 alarm_time 에 담아줄게
// 그러면 while문 돌다가 alarm_time이랑 지금 시간이랑(clock()) 같으면 그때 멈춰줘.