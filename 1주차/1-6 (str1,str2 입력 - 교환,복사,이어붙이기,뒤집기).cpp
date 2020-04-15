#include <stdio.h>
#include <string.h>
void reverse(char *str)
{
	int i, len;
	char temp;
	len = strlen(str);
	for (i = 0; i <= len / 2; i++) {
		temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}
	str[len]='\0';
}
void main(){
char str1[100];
char str2[100];
char str3[200];
char str4[100];
char temp[100];
int len1, len2, len3, len4;
printf("(1) 입력 str1: "); scanf("%s" , str1);
printf("    입력 str2: "); scanf("%s", str2);
strcpy(temp,str1);
strcpy(str1,str2);
strcpy(str2,temp);

len1 = strlen(str1);
len2 = strlen(str2);
printf("(2) 교환 str1=%s str2=%s\n",str1,str2);
printf("len1=%d len2=%d\n",len1,len2);
strcpy(str3,str2);
printf("(3) 복사 str3=%s\n",str3);
strcat(str3," ");
strcat(str3,str1);
strcat(str3,"computer engineering");
printf("(4) 이어붙이기 str3=%s\n",str3);
len3= strlen(str3);
printf("len3=%d\n",len3);
reverse(str1);
//str1[len1]='\0';
printf("(5) 뒤집기 str1=%s\n",str1);
printf("len1=%d\n",len1);
}