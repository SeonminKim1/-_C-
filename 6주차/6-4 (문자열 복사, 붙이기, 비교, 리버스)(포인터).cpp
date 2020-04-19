#include <stdio.h>
#include <string.h>


int mystrlen(char *str)
{
int n=0;
/*		while(1)
	{
		if(*str == '\0')break;
		str++; n++;
	}
	return n;
	*/
	while(*str !='\0')
	{
	str++; 
	n++;
	}
	return n;
}

char *mystrcpy(char *to, char *from)
{
	while(*from != '\0'){
		*to=*from;
	to++;   // *to 는 값이니까. 
	from++;
}
	*to='\0';
return to;
}


int mystrcmp(char *s1, char *s2)
{
	while(*s1 !='\0' && *s2 !='\0')
	{
		s1++;
		s2++;
	}
	if(*s1==*s2) return 0;
	if(*s1>*s2) return -1;
	if(*s1<*s2) return 1;
// return (*s1>*s2) ? 1 : -1;
}
char *mystrcat(char *to, char *from)
{
	while(*to != '\0') 
	{
		to++;
	}
	while(*from !='\0')
	{ 
		*to=*from;
		to++; from++;
	}
	*to='\0';
return to;
}

// 한글을 고려한 reverse 작성
void reverse(char *to, char *from)
{
int i,j,len;
	len=strlen(from);
	j=len-1;
	for(i=0; i<len;)
	{
		if((*(from+j) & 0x80) && (*(from+j-1) & 0x80)){
			// 한글
			*(to+i)=*(from+j-1);
			*(to+i+1)=*(from+j);
			i=i+2;
			j=j-2;
		}
		else{
			*(to+i)=*(from+j);
			i=i+1;
			j=j-1;
		}
	}
	*(to+len)='\0';
}

void main()
{
	char str1[100] = "한성대학교";
	char str2[100] = "University";
	char str3[100] = "Computer";
	char str4[100] = "Engineering";
	char str5[100];
	char str6[100];
	int ret;

	ret = mystrlen(str1);
	printf("mystrlen(%s)=%d\n", str1, ret);
	ret = mystrcmp(str1, str1);
	printf("mystrcmp(%s, %s) = %d\n", str1, str1, ret);
	ret = mystrcmp(str1, str2);
	printf("mystrcmp(%s, %s) = %d\n", str1, str2, ret);
	ret = mystrcmp(str1, str3);
	printf("mystrcmp(%s, %s) = %d\n", str1, str3, ret);
	mystrcpy(str5, str1);
	printf("mystrcpy str5 = %s\n", str5);
	mystrcat(str5, " ");
	mystrcat(str5, str2);
	printf("mystcat str5 = %s\n", str5);
	reverse(str6, str5);
	printf("reverse str5 = %s\n", str6);
}