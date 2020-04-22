#include <stdio.h>
void main()
{
	FILE *fp;
	char ch;
	char filename[100];
	char buf[100];
	int id=1492001;
	char name[20] = "홍길동";
	char phone[20] = "010-1234-5678";
	
	printf("출력 파일 명 : ");
	scanf("%s", filename);
	fp=fopen(filename,"w");//w읽고 쓰기 모드 wt : 쓰고 읽기 모드 rt:수정+읽기모드 r:읽기만
	scanf("%d %s %s", &id , name, phone); //키보드에서 입력 받아 저장하는 경우
	
	fprintf(fp,"%d\n",id);
	fprintf(fp,"%s\n",name);
	fprintf(fp,"%s\n",phone);
	// 파일에 입력.
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