#include <stdio.h>
// 12월 전체 출력
void main(){
	int m[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int i,j,k;
	int allday=0,startday=1;

	for(i=0; i<12; i++){
		printf("         %d월    \n",i+1);
		allday=allday+m[i];
		printf(" 일 월 화 수 목 금 토 \n");
		for(k=0; k<startday; k++){  // 공백을위함. 
			printf("   ");
		}
		for(j=1; j<=m[i]; j++){ // 그 월의 날짜 입력.
			printf("%3d",j);
			if((j+startday)%7==0)printf("\n"); // j+startday -> 공백과 날짜가 합이 7배수면. = 3일까지면 공백4일 합 7.
		}
		startday=allday%7; // 그 달에서 7씩 뺴서 공백의 갯수.
		printf("\n\n");
	}
}