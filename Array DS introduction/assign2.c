#include <stdio.h>

int second_largest(int A[], int N)
{
	int max, second_max;
	max=second_max=0;
	for(int i=0; i<N; i++)
	{
		if(A[i]>max)
		{
			second_max=max;
			max=A[i];
		}
		else if(A[i]<max && A[i]>second_max)
		{
			second_max=A[i];
		}
	}
	return second_max;
}

int main()
{
	int arr[]={10, 12, 8, 17, 25, 35, 19};
	int size=sizeof(arr)/sizeof(int);

	int res=second_largest(arr, size);
	printf("Second largest is %d\n",res);
	return 0;
}