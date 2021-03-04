#include <stdio.h>

void Bubble_sort(int arr[], int N)
{
	int temp;
	for(int round=1; round<N; round++)
	{
		printf("Working on round %d\n",round);
		for(int i=0; i<N-round; i++)
		{
			if(arr[i]>arr[i+1])
			{
				temp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=temp;
			}
		}
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
	printf("Enter %d values: ", n);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}

	Bubble_sort(arr,n);
	printf("\nSorted Bubble: ");
	display(arr,n);
	printf("\n");
	return 0;
}