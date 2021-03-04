#include <stdio.h>

void insertion_sort(int arr[],int N)
{
	int temp,j;
	for(int i=1; i<N; i++)
	{
		temp=arr[i];
		for(j=i-1; j>=0 && temp<arr[j]; j--)
		{
			arr[j+1]=arr[j];
		}
		arr[j+1]=temp;
	}
}

void display(int arr[], int N)
{
	for(int i=0; i<N; i++)
	{
		printf("%d ", arr[i]);
	}
}

int main()
{
	int arr[50], n;
	printf("Enter how many values: ");
	scanf("%d",&n);
	printf("Enter %d values: ",n);

	for(int i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}

	insertion_sort(arr,n);
	printf("\nInsertion sorted: ");
	display(arr,n);
	return 0;
}