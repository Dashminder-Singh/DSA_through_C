#include <stdio.h>

void Selection_sort(int arr[], int N)
{
	int index,temp;
	for(int i=0; i<N-1; i++)
	{
		index=i;
		for(int j=i+1; j<N; j++)
		{
			if(arr[j]<arr[index])
			{
				index=j;
			}
		}
		temp=arr[i];
		arr[i]=arr[index];
		arr[index]=temp;
	}
}

void display(int arr[], int n)
{
	for(int i=0; i<n; i++)
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

	Selection_sort(arr,n);
	printf("\nSelection Sorted: ");
	display(arr,n);
	return 0;
}