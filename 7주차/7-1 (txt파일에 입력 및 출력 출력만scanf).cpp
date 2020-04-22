#include <stdio.h>
void main()
{
	FILE *fp;
	char ch;
	char filename[100];
	char buf[100];
	int id=1492001;
	char *name = "홍길동";
	char *phone = "010-1234-5678";
	fp=fopen("data.txt","w");//w읽고 쓰기 모드
	//scanf("%d %s %s", &id , &name, &phone); 키보드에서 입력 받아 저장하는 경우
	fprintf(fp,"%d\n",id);
	fprintf(fp,"%s\n",name);
	fprintf(fp,"%s\n",phone);
	fclose(fp);
	printf("입력 파일 명 : ");
	scanf("%s",filename);
	fp=fopen(filename,"r");
	fscanf(fp,"%d",&id);
	printf("학번=%d\n",id);
	fscanf(fp,"%s",buf);
	printf("이름=%s\n",buf);
	fscanf(fp,"%s",buf);
	printf("전화=%s\n",buf);
	fclose(fp);
}