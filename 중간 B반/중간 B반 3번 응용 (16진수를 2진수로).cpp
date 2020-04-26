#include <stdio.h>
#include <string.h>
//기말대비 : 16진수 ->2진수 or 8진수 ->2진수
// 8진수는 %o   앞에 0x 붙이고 싶으면 %#o하면 됨. %#x나.
int bitnami(int aa){
	if(aa>=2){
	bitnami(aa/2);
	printf("%d",aa%2);
	}
	else {
		if(aa%2==1)printf("1");
		else printf("0");
	}
	return 0;
}
void main(){ 
	int i ,j,sum=0;
	int ntest=3;
	int len_n, aa;
	char n[80];
	while(ntest--){
	scanf("%s", &n);
	len_n= strlen(n);
	for(i=0; i<len_n; i++){
		sum=sum+(n[i]-'0'-7);
		sum=sum*16;
	}
	printf("%d\n",sum/16);// 16진수를 10진수로 바꿈.
	aa=sum/16; //16진수를 10진수로 바꾼 수 .
	bitnami(aa);
	}
}