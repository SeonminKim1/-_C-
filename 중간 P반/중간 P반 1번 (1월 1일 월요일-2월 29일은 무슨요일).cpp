#include <stdio.h>

void main(){
	int m[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	char *a[12] = { "��","��","ȭ","��","��","��","��"};
	int month, day, startday, i,j,h;
	int ntest,allday;
	printf("1�� 1���� ���� �������� ���Ͻÿ� (�Ͽ���(0) ~ �����(6)\n");
	scanf("%d",&startday);
	scanf("%d",&ntest);
	for(j=0; j<ntest; j++){
		scanf("%d %d",&month, &day);
		allday=0;
		for(i=0; i<month-1; i++){allday=allday+m[i];}
		if(day>m[month-1])
		printf("N/A\n");
		else{ 
		printf("%s����\n",a[(allday+day+startday-1)%7]);
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
char *b[7]={"�Ͽ���","������","ȭ����","������","�����","�ݿ���","�����"};
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