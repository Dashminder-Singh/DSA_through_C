#include <stdio.h>

int greatest(int A[], int N)
{
	int max=0;
	for(int i=0; i<N; i++)
	{
		if(A[i]>max)
		{
			max=A[i];
		}
	}
	return max;
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
	int ans=greatest(arr,n);
	printf("Greatest number of the array is: %d",ans);
	return 0;
}