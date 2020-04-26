#include <stdio.h>

void main(){
	int m[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	char *a[12] = { "일","월","화","수","목","금","토"};
	int month, day, startday, i,j,h;
	int ntest,allday;
	printf("1월 1일이 무슨 요일인지 정하시오 (일요일(0) ~ 토요일(6)\n");
	scanf("%d",&startday);
	scanf("%d",&ntest);
	for(j=0; j<ntest; j++){
		scanf("%d %d",&month, &day);
		allday=0;
		for(i=0; i<month-1; i++){allday=allday+m[i];}
		if(day>m[month-1])
		printf("N/A\n");
		else{ 
		printf("%s요일\n",a[(allday+day+startday-1)%7]);
		}
	}
}

/*
#include <stdio.h>

void main()
{
int ntest, month,day,allday=0;
int i,j;
int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int weday;
char *b[7]={"일요일","월요일","화요일","수요일","목요일","금요일","토요일"};
scanf("%d",&ntest);
while(ntest--){
	scanf("%d %d",&month,&day);
	if(month>12 || month<1 || day>a[month-1] || day<0)printf("N/A\n");
	else {
		for(i=0; i<month-1; i++){
			allday=allday+a[i];
			}
		printf("%s\n",b[(allday+day-1+3)%7]);
		}
	allday=0;
	}
}
*/