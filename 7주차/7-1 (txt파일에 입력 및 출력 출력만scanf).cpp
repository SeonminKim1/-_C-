#include <stdio.h>
void main()
{
	FILE *fp;
	char ch;
	char filename[100];
	char buf[100];
	int id=1492001;
	char *name = "ȫ�浿";
	char *phone = "010-1234-5678";
	fp=fopen("data.txt","w");//w�а� ���� ���
	//scanf("%d %s %s", &id , &name, &phone); Ű���忡�� �Է� �޾� �����ϴ� ���
	fprintf(fp,"%d\n",id);
	fprintf(fp,"%s\n",name);
	fprintf(fp,"%s\n",phone);
	fclose(fp);
	printf("�Է� ���� �� : ");
	scanf("%s",filename);
	fp=fopen(filename,"r");
	fscanf(fp,"%d",&id);
	printf("�й�=%d\n",id);
	fscanf(fp,"%s",buf);
	printf("�̸�=%s\n",buf);
	fscanf(fp,"%s",buf);
	printf("��ȭ=%s\n",buf);
	fclose(fp);
}