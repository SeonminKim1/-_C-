#include <stdio.h>
#include <string.h>
#include <ctype.h>
void main()
{
	char c;
int all=0; //전체문자갯수 계산하려고
int alpha=0; // 전체 알파벳수 계산하려고 함.
int count[26]={0};
while(c=getchar() != EOF) // if(c==EOF) -> 문장의 끝이면.
{
	all++;
	if(isalpha(c)) // isalpha(" ") 알파벳인지 판단.
	{
		alpha++;
		count[toupper(c)-'A']++; // toupper(c) ->소문자를 대문자로 ex)A=10,B=11 
	}
}
printf("\n\n전체문자수=%d알파벳수=%d\n",all,alpha);
for(c='A'; c<='Z'; c++)
{
	printf("%c:%3d(%5.2lf%%)",c,count[c-'A'],(double)count[c-'A']/alpha*100);
	if(c-'A'%5==4)
		printf("\n");
}
printf("\n");
}