#include <stdio.h>
#include <string.h>
#include <ctype.h>
void main()
{
	char c;
int all=0; //��ü���ڰ��� ����Ϸ���
int alpha=0; // ��ü ���ĺ��� ����Ϸ��� ��.
int count[26]={0};
while(c=getchar() != EOF) // if(c==EOF) -> ������ ���̸�.
{
	all++;
	if(isalpha(c)) // isalpha(" ") ���ĺ����� �Ǵ�.
	{
		alpha++;
		count[toupper(c)-'A']++; // toupper(c) ->�ҹ��ڸ� �빮�ڷ� ex)A=10,B=11 
	}
}
printf("\n\n��ü���ڼ�=%d���ĺ���=%d\n",all,alpha);
for(c='A'; c<='Z'; c++)
{
	printf("%c:%3d(%5.2lf%%)",c,count[c-'A'],(double)count[c-'A']/alpha*100);
	if(c-'A'%5==4)
		printf("\n");
}
printf("\n");
}