#include <stdio.h>
//숫자 콤마 넣기
// 콤마로 포함한 두 수를 문자열로 받고 그 합을 콤마로 포함해서 출력
// 오류가 있는 경우 N/A로 출력
//기말 예상 문제 123,456 + 12,345,678,100
//TEST CASE 3
//1,234 5,007
//1234 45,678 --> N/A or 57,912
//123,456 + 12,345,678,100
//문자열로 인식하여 덧셈. 콤마를 빼고
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
//printf("%d\n",_CRT_INT_MAX); 최댓값 구하기 21억이 넘게되면 문자열로 계산하는게 보통. 
void main(void){
	int n;
	printf("정수 입력 : ");
	 
	scanf("%d", &n);
	printcomma(n);
	printf("\n");
}
