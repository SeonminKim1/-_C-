#include <stdio.h>
#include <time.h>
void main()
{
	char aa[7][4]={"��","��","ȭ","��","��","��","��"}; // *aa[]
	time_t now;
	time(&now);
	printf("now = %d\n", &now);
	printf("ctime<> : %s",ctime(&now));
	struct tm *tp;
	tp=localtime(&now);
	printf("%d�� %d�� %d�� %s���� %d�� %d�� %d��",tp->tm_year+1900,tp->tm_mon,tp->tm_mday,
			aa[tp->tm_wday],tp->tm_hour, tp->tm_min, tp->tm_sec);
}