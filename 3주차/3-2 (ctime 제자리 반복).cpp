#include <stdio.h>
#include <time.h>
void main()
{
char aa[7][4]={"��","��","ȭ","��","��","��","��"}; // *aa[]
time_t now, old_now=0;
struct tm *tp;
while(1)
{
	time(&now);
	tp=localtime(&now);
	if(now != old_now) // ���� �ȰŸ����ϴ°�
	printf("%d�� %d�� %d�� %s���� %d�� %d�� %d��\r",tp->tm_year+1900,tp->tm_mon,tp->tm_mday,
			aa[tp->tm_wday],tp->tm_hour, tp->tm_min, tp->tm_sec);
	old_now=now;
}
}