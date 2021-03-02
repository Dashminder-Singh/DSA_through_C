#include <stdio.h>

int sum(int A[],int N);

int main()
{
	int n;
	printf("Enter how many numbers you want: ");
	scanf("%d",&n);

	int arr[n];
	printf("Enter numbers in array: ");
	for(int i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}

	int ans=sum(arr,n);
	printf("Sum of %d numbers is= %d",n,ans);
	return 0;
}

int sum(int A[], int N)
{
	int sum=0;
	for(int i=0; i<N; i++)
	{
		sum=sum+A[i];
	}
	return sum;
}
