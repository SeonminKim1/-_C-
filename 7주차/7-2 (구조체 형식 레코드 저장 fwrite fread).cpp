#include <stdio.h>
typedef struct Student
{
	int id;
	char name[20];
	char phone[20];
};
void main()
{//w:�а�����, wt:���� �б��� , rt:����+�б�, r :�б⸸
	struct Student data = {1493002,"ȫ�浿","010-1234-5678"};
	FILE *fp;
	fp=fopen("data.txt","w+b"); //b=����ȭ���
	fwrite(&data,sizeof(data),1,fp); // ���Ͽ��� data ��ġ�� ����Ÿ size * 1�� ���
	fclose(fp);
	fp=fopen("data.txt","r+b");
	fread(&data,sizeof(data),1,fp); // ���Ͽ��� data ��ġ�� ����Ÿ size* 1�� �Է�
	printf("�й�=%d\n",data.id);
	printf("�̸�=%s\n",data.name);
	printf("��ȭ=%s\n",data.phone);
	fclose(fp);
}