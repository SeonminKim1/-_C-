#include <stdio.h>
#include <string.h>
//�⸻��� : 16���� ->2���� or 8���� ->2����
// 8������ %o   �տ� 0x ���̰� ������ %#o�ϸ� ��. %#x��.
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
			sum=sum*2; // �������� *10 8������ *8
			}
			if(i==len_n-1)printf("%X\n",sum/2); // if(�������϶�)��� /2�������.
		}
		sum=0;
	}
}
		