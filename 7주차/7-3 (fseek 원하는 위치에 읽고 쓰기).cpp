#include <stdio.h>
typedef struct Student{
	int id;
	char name[20];
	char phone[20];
};
void main(){
	struct Student data;
	FILE *fp;
	int i;
	fp=fopen("data.txt","wb");
	for(i=0; i<5; i++){
		scanf("%d %s %s", &data.id, data.name, data.phone);
		fwrite(&data,sizeof(data),1,fp);
	}
	fclose(fp);
	fp=fopen("data.txt","rb");
	while(1){
		printf("데이타번호 : ");
		scanf("%d", &i);
		if(i==99)break;
		fseek(fp,i*sizeof(data),SEEK_SET); // (fp, offset , whence) 
		// whence부터 offset만큼 이동
		// SEEK_SET : 0 / SEEK_CUR : 1 / SEEK_END : 2
		// fseek(fp,n*sizeof(struct Student),0)
		fread(&data,sizeof(data),1,fp);
		printf("학번=%d\n",data.id);
		printf("이름=%s\n",data.name);
		printf("전화=%s\n",data.phone);
	}
	fclose(fp);
}