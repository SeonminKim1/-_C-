#include <stdio.h> // ģȭ�� - �μ��� ����� ������ ���� ������.
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
		printf("�� ���� �Է��ϼ��� ");
		scanf("%d %d",&n1,&n2);
		if(sum(n1)==n2 && sum(n2)==n1)printf("YES\n");
		else printf("ģȭ���� �ƴմϴ�. �� ����� ���� ���� %d %d �Դϴ�.\n", sum(n1), sum(n2));
	}
}