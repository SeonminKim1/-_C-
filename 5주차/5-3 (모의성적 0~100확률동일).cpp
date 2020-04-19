#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
int r,i,n,sum=0;
int count[9]={0};
char *grade[9]={"A+","A ","B+","B ","C+","C ","D+","D ","F "};
scanf("%d",&n);
for(i=0; i<n; i++){
	r=rand()%101;
	if(r>=95 && r<=100)count[0]++;
	else if(r>=90 && r<95)count[1]++;
	else if(r>=85 && r<90)count[2]++;
	else if(r>=80 && r<85)count[3]++;
	else if(r>=75 && r<80)count[4]++;
	else if(r>=70 && r<75)count[5]++;	
	else if(r>=65 && r<70)count[6]++;
	else if(r>=60 && r<65)count[7]++;
	else count[8]++;
	sum=sum+r;
	printf("%d ", r);
}
printf("\n");
printf("n=%d ЦђБе=%.2lf\n",n,(double)sum/n);
for(i=0; i<9; i++)
	printf("%s : %d (%5.2lf%%)\n",grade[i],count[i],(double)count[i]/n*100);
}