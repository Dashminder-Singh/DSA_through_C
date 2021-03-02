#include <stdio.h>

float avarage(int A[], int N)
{
	int sum=0;
	float avg;
	for(int i=0; i<N; i++)
	{
		sum=sum+A[i];
	}
	avg=(float)sum/N;
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
	float ans=avarage(arr,n);
	printf("Avarage of %d numbers is: %.2f",n,ans);
	return 0;
}