#include <stdio.h>
void main()
{
	int year,month,day;
	char num[7];
	printf("주민번호 앞자리 : ");
	scanf("%s",num);
	year=(num[0]-48)*10+(num[1]-48)+1900;
	month=(num[2]-48)*10+(num[3]-48);
	day=(num[4]-48)*10+(num[5]-48); // (num[4]-'0')*10+(num[5]-'0');
	printf("%d년 %d월 %d일 생입니다\n",year,month,day);
}