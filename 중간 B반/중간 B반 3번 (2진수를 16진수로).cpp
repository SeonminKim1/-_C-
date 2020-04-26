#include <stdio.h>
#include <string.h>
//기말대비 : 16진수 ->2진수 or 8진수 ->2진수
// 8진수는 %o   앞에 0x 붙이고 싶으면 %#o하면 됨. %#x나.
void main()
{
	int i ,j,sum=0;
	int ntest;
	int len_n;
	char n[80];
	scanf("%d", &ntest);
	while(ntest--)
	{
		scanf("%s", &n);
		len_n=strlen(n);
		for(i=0; i<len_n; i++)
		{
			if(n[i]>'1' || n[i]<'0'){printf("N/A\n");break;}
			else{
			sum=sum+n[i]-'0';
			sum=sum*2; // 십진수면 *10 8진수면 *8
			}
			if(i==len_n-1)printf("%X\n",sum/2); // if(마지막일때)출력 /2해줘야함.
		}
		sum=0;
	}
}
		