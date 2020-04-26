//숫자 콤마 넣기
// 콤마로 포함한 두 수를 문자열로 받고 그 합을 콤마로 포함해서 출력
// 오류가 있는 경우 N/A로 출력
//기말 예상 문제 123,456 + 12,345,678
//TEST CASE 3
//1,234 5,007
//1234 45,678 --> N/A or 57,912
//123,456 + 12,345,678,100
//문자열로 인식하여 덧셈. 콤마를 빼고
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
		printf(",%03d", n % 1000); // 03d라고 쓰는 건 12005 라고 쓰면 125라고 나오는거 방지
	}
}
int ok(char num1[],char num2[]){ // , 없는 경우 검사하는 함수
	int i, count1=0, count2=0;
	int len_num1=strlen(num1);
	int len_num2=strlen(num2);
		for(i=0; i<len_num1; i++){ if(num1[i]==',')count1++; }
		for(i=0; i<len_num2; i++){ if(num2[i]==',')count2++; }
	if(count1==0 || count2==0)return 0; // ,가 없는 경우 오류나게.
	else return 1;
}

void main(){ // 전체구상 : num1 숫자만 ab1배열에 담음. ab1을 정수화 ab2랑 더함. 
int i, j=0, k=0, n;
int len_num1, len_num2, len_ab1, len_ab2;
int sum1=0, sum2=0, ntest;
char num1[20]={0}, ab1[20]={0};
char num2[20]={0}, ab2[20]={0};
scanf("%d",&ntest);
while(ntest--){
	sum1=0, sum2=0, j=0, k=0;
	for(i=0; i<20; i++){num1[i]=0; num2[i]=0; ab1[i]=0; ab2[i]=0;} // 배열초기화

	printf("콤마를 포함한 정수 두개 입력 : "); scanf("%s %s",&num1, &num2);
	len_num1=strlen(num1); len_num2=strlen(num2);
	if(ok(num1,num2)==0)printf("NO\n");
	else{
	for(int i=0; i<strlen(num1); i++){ // num1 중 숫자만 ab1[]에 담기
		if(num1[i] != ','){ ab1[j]=num1[i]; j++; } 
	} 
		len_ab1=strlen(ab1); // ab1에 담긴거 길이 쟤고
		for(i=0; i<len_ab1; i++){ // ab1 값들 정수화
		sum1=sum1+(ab1[i]-'0'); sum1=sum1*10; 
		}
	for(int i=0; i<strlen(num2); i++){ // num2 중 숫자만 ab2에 담기
		if(num2[i] != ','){ab2[k]=num2[i]; k++; }
	}
		len_ab2=strlen(ab2); // ab2에 담긴거 길이 쟤고
		for(i=0; i<len_ab2; i++){   // ab2 값들 정수화
		sum2=sum2+(ab2[i]-'0');	sum2=sum2*10;
		}
	n=(sum1/10)+(sum2/10);
	printcomma(n);
	printf("\n");
	}
	}
}