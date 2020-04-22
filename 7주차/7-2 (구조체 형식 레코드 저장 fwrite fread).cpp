#include <stdio.h>
typedef struct Student
{
	int id;
	char name[20];
	char phone[20];
};
void main()
{//w:읽고쓰기모드, wt:쓰고 읽기모드 , rt:수정+읽기, r :읽기만
	struct Student data = {1493002,"홍길동","010-1234-5678"};
	FILE *fp;
	fp=fopen("data.txt","w+b"); //b=이진화모드
	fwrite(&data,sizeof(data),1,fp); // 파일에서 data 위치에 데이타 size * 1개 출력
	fclose(fp);
	fp=fopen("data.txt","r+b");
	fread(&data,sizeof(data),1,fp); // 파일에서 data 위치에 데이타 size* 1개 입력
	printf("학번=%d\n",data.id);
	printf("이름=%s\n",data.name);
	printf("전화=%s\n",data.phone);
	fclose(fp);
}