#include <stdio.h>
#include <string.h>
//�⸻��� : 16���� ->2���� or 8���� ->2����
// 8������ %o   �տ� 0x ���̰� ������ %#o�ϸ� ��. %#x��.
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
	printf("%d\n",sum/16);// 16������ 10������ �ٲ�.
	aa=sum/16; //16������ 10������ �ٲ� �� .
	bitnami(aa);
	}
}