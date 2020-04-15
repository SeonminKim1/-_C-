#include <stdio.h>
#include <malloc.h>
int find_max(int arr[],int n)
{
int i;
int max=arr[0];
for(i=0;i<n; i++)
{
	if(arr[i]>max)
		max=arr[i];
}
return max;
}

int find_min(int arr[], int n)
{
	int i;
	int min=arr[0];
	for(i=0; i<n; i++)
	{
		if(arr[i]<min)
			min=arr[i];
	}
	return min;
}

int sum(int arr[], int n)
{
int i,hab=0;
for(i=0; i<n; i++)
	{
	hab=hab+arr[i];
	}
return hab;
}

int main()
{
	int *arr;
	int n,i,j,m,k;
	scanf("%d",&n);
	for(i=0;i<n; i++)
	{
		scanf("%d",&m);
		arr=(int *)malloc(sizeof(int)*m);
	for(j=0; j<m; j++)
	{
		scanf("%d",&k);
		arr[j]=k;
	}
	printf("%d %d %d\n",sum(arr,m),find_max(arr,m),find_min(arr,m));
	free(arr);
	}
}