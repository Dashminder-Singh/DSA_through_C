#include <stdio.h>

void modified_bubble(int arr[],int N)
{
	int temp, flag=0;
	for(int round=1; round<N; round++)
	{
		printf("Working on round %d\n", round);
		flag=1;
		for(int i=0; i<N-round; i++)
		{
			if(arr[i]>arr[i+1])
			{
				flag=0;
				temp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=temp;
			}
		}
		if(flag==1)
			break;
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
	printf("Enter how many: ");	
	scanf("%d",&n);

	printf("Enter %d values: ",n);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	modified_bubble(arr,n);
	display(arr,n);
	return 0;
}