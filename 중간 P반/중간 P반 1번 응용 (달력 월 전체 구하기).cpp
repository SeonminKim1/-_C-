#include <stdio.h>
// 12�� ��ü ���
void main(){
	int m[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int i,j,k;
	int allday=0,startday=1;

	for(i=0; i<12; i++){
		printf("         %d��    \n",i+1);
		allday=allday+m[i];
		printf(" �� �� ȭ �� �� �� �� \n");
		for(k=0; k<startday; k++){  // ����������. 
			printf("   ");
		}
		for(j=1; j<=m[i]; j++){ // �� ���� ��¥ �Է�.
			printf("%3d",j);
			if((j+startday)%7==0)printf("\n"); // j+startday -> ����� ��¥�� ���� 7�����. = 3�ϱ����� ����4�� �� 7.
		}
		startday=allday%7; // �� �޿��� 7�� ���� ������ ����.
		printf("\n\n");
	}
}