#include <stdio.h>
void main()
{
	FILE *fp;
	char ch;
	char filename[100];
	char buf[100];
	int id=1492001;
	char name[20] = "ȫ�浿";
	char phone[20] = "010-1234-5678";
	
	printf("��� ���� �� : ");
	scanf("%s", filename);
	fp=fopen(filename,"w");//w�а� ���� ��� wt : ���� �б� ��� rt:����+�б��� r:�б⸸
	scanf("%d %s %s", &id , name, phone); //Ű���忡�� �Է� �޾� �����ϴ� ���
	
	fprintf(fp,"%d\n",id);
	fprintf(fp,"%s\n",name);
	fprintf(fp,"%s\n",phone);
	// ���Ͽ� �Է�.
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