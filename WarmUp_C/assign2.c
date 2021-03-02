#include <stdio.h>

int avarage(int A[], int N)
{
	int sum=0, avg;
	for(int i=0; i<N; i++)
	{
		sum=sum+A[i];
	}
	avg=sum/N;
	return avg;
}

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
	int ans=avarage(arr,n);
	printf("Avarage of %d numbers is: %d",n,ans);
	return 0;
}