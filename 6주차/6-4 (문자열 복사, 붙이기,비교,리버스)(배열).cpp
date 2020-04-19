#include <stdio.h>
#include <string.h>
void reverse(char to[], char from[])
{
	int i,len;               // 수 뒤집기.
	len=strlen(from);
	for(i=0; i<len; i++)
	to[i]=from[len-1-i];
	to[len]='\0'; // 마지막 끝에 널값 채워주기.
	
}
// 한글을 고려한 reverse
void reverseK(char to[], char from[])
{
	// 한글 2bytes를 고려한 reverse
}
void main()
{
	char str1[100] = "Hansung";
	char str2[100] = "University";
	char str3[100] = "Computer";
	char str4[100] = "Engineering";
	char str5[100];
	char str6[100];
	int ret;

	ret = strlen(str1);
	printf("strlen(%s)=%d\n", str1, ret);
	ret = strcmp(str1, str1);
	printf("strcmp(%s, %s) = %d\n", str1, str1, ret);
	ret = strcmp(str1, str2);
	printf("strcmp(%s, %s) = %d\n", str1, str2, ret);
	ret = strcmp(str1, str3);
	printf("strcmp(%s, %s) = %d\n", str1, str3, ret);

	strcpy(str5, str1);
	printf("strcpy str5 = %s\n", str5);
	strcat(str5, " ");
	strcat(str5, str2);
	printf("stract str5, str2 = %s\n", str5);

	reverse(str6, str5);
	printf("reverse str5 = %s\n", str6);
}