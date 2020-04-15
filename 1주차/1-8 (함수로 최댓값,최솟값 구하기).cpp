#include <stdio.h>

void print_array(int arr[], int n)
{
int i;
for (i=0;i<n;i++)
	printf("%d ", arr[i]);
printf("\n");
}

double avg(int arr[], int n)
{
int i;
double sum = 0.;
for (i=0;i<n;i++)
	sum = sum + arr[i];
return sum/n;
}

int max(int arr[], int n)
{
	int i;
	int max = arr[0];
	for (i=1;i<n;i++) 
	{
		if (arr[i]>max) 
		max = arr[i];
	}
	return (max);
}

int min(int arr[], int n)
{
int i;
int min = arr[0];
for (i=1;i<n;i++) 
	{
	if (arr[i]<min) 
		min = arr[i];
	}
return(min);
}

void main()
{
int arr[10] = {10, 30, 5, 20, 44, 3, 100, 88, 9, 101};
print_array(arr, 10);
printf("평균 = %lf\n", avg(arr, 10));
printf("최대 = %d\n", max(arr, 10));
printf("최소 = %d\n", min(arr, 10));
}