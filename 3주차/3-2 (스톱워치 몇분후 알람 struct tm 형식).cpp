#include <stdio.h>
#include <time.h>
void main()
{
int n;
char aa[7][4]={"일","월","화","수","목","금","토"}; // *aa[]
time_t now, old_now=0,alarm;
printf("몇분 후 알람?");
scanf("%d",&n);
struct tm *tp;
printf("\n");
time(&now);
alarm=now+n*60;
tp=localtime(&alarm);
printf("알람시간 : %d년 %d월 %d일 %s요일 %d시 %d분 %d초\n",tp->tm_year+1900,tp->tm_mon,
	tp->tm_mday,aa[tp->tm_wday],tp->tm_hour,tp->tm_min,tp->tm_sec);
while(1)
{
	time(&now);
	tp=localtime(&now);
	if(now != old_now) // 깜박 안거리게하는거
	printf("현재시간 : %d년 %d월 %d일 %s요일 %d시 %d분 %d초\r",tp->tm_year+1900,tp->tm_mon,tp->tm_mday,
			aa[tp->tm_wday],tp->tm_hour, tp->tm_min, tp->tm_sec);
	old_now=now;
	if(alarm==now)break;
}
printf("\n!!!!!!알람!!!!!!\n");
}

