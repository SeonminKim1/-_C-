//���� �޸� �ֱ�
// �޸��� ������ �� ���� ���ڿ��� �ް� �� ���� �޸��� �����ؼ� ���
// ������ �ִ� ��� N/A�� ���
//�⸻ ���� ���� 123,456 + 12,345,678
//TEST CASE 3
//1,234 5,007
//1234 45,678 --> N/A or 57,912
//123,456 + 12,345,678,100
//���ڿ��� �ν��Ͽ� ����. �޸��� ����
#include <stdio.h>
#include <string.h>
void printcomma(int n){
	if(n<0){
		printf("-");
		n=-n;
		printcomma(n);
	}
	if (n < 1000)
		printf("%d", n);
	else{
		printcomma(n / 1000);
		printf(",%03d", n % 1000); // 03d��� ���� �� 12005 ��� ���� 125��� �����°� ����
	}
}
int ok(char num1[],char num2[]){ // , ���� ��� �˻��ϴ� �Լ�
	int i, count1=0, count2=0;
	int len_num1=strlen(num1);
	int len_num2=strlen(num2);
		for(i=0; i<len_num1; i++){ if(num1[i]==',')count1++; }
		for(i=0; i<len_num2; i++){ if(num2[i]==',')count2++; }
	if(count1==0 || count2==0)return 0; // ,�� ���� ��� ��������.
	else return 1;
}

void main(){ // ��ü���� : num1 ���ڸ� ab1�迭�� ����. ab1�� ����ȭ ab2�� ����. 
int i, j=0, k=0, n;
int len_num1, len_num2, len_ab1, len_ab2;
int sum1=0, sum2=0, ntest;
char num1[20]={0}, ab1[20]={0};
char num2[20]={0}, ab2[20]={0};
scanf("%d",&ntest);
while(ntest--){
	sum1=0, sum2=0, j=0, k=0;
	for(i=0; i<20; i++){num1[i]=0; num2[i]=0; ab1[i]=0; ab2[i]=0;} // �迭�ʱ�ȭ

	printf("�޸��� ������ ���� �ΰ� �Է� : "); scanf("%s %s",&num1, &num2);
	len_num1=strlen(num1); len_num2=strlen(num2);
	if(ok(num1,num2)==0)printf("NO\n");
	else{
	for(int i=0; i<strlen(num1); i++){ // num1 �� ���ڸ� ab1[]�� ���
		if(num1[i] != ','){ ab1[j]=num1[i]; j++; } 
	} 
		len_ab1=strlen(ab1); // ab1�� ���� ���� ����
		for(i=0; i<len_ab1; i++){ // ab1 ���� ����ȭ
		sum1=sum1+(ab1[i]-'0'); sum1=sum1*10; 
		}
	for(int i=0; i<strlen(num2); i++){ // num2 �� ���ڸ� ab2�� ���
		if(num2[i] != ','){ab2[k]=num2[i]; k++; }
	}
		len_ab2=strlen(ab2); // ab2�� ���� ���� ����
		for(i=0; i<len_ab2; i++){   // ab2 ���� ����ȭ
		sum2=sum2+(ab2[i]-'0');	sum2=sum2*10;
		}
	n=(sum1/10)+(sum2/10);
	printcomma(n);
	printf("\n");
	}
	}
}