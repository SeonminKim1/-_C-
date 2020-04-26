#include <stdio.h> // 친화수 - 두수의 약수의 각각의 합이 서로임.
int sum(int n){
	int i,sum=0;
	for(i=1; i<n; i++){
		if(n%i==0)sum=sum+i;
	}
	return sum;
}

int main()
{
	int i,j,n1,n2;
	int ntest;
	scanf("%d", &ntest);
	while(ntest--)
	{
		printf("두 수를 입력하세요 ");
		scanf("%d %d",&n1,&n2);
		if(sum(n1)==n2 && sum(n2)==n1)printf("YES\n");
		else printf("친화수가 아닙니다. 두 약수의 합은 각각 %d %d 입니다.\n", sum(n1), sum(n2));
	}
}