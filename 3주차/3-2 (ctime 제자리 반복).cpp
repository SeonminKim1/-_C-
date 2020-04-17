#include <stdio.h>
#include <time.h>
void main()
{
char aa[7][4]={"일","월","화","수","목","금","토"}; // *aa[]
time_t now, old_now=0;
struct tm *tp;
while(1)
{
	time(&now);
	tp=localtime(&now);
	if(now != old_now) // 깜박 안거리게하는거
	printf("%d년 %d월 %d일 %s요일 %d시 %d분 %d초\r",tp->tm_year+1900,tp->tm_mon,tp->tm_mday,
			aa[tp->tm_wday],tp->tm_hour, tp->tm_min, tp->tm_sec);
	old_now=now;
}
}