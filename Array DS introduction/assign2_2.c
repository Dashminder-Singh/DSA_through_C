#include <stdio.h>

int third_largest(int A[], int N)
{
	int max, second_max, third_max;
	max=second_max=third_max=0;
	for(int i=0; i<N; i++)
	{
		if(A[i]>max)
		{
			third_max=second_max;
			second_max=max;
			max=A[i];
		}
		else if(A[i]>second_max)
		{
			third_max=second_max;
			second_max=A[i];
		}
		else if(A[i]<max && A[i]>third_max)
		{
			third_max=A[i];
		}
	}
	return third_max;
}

int main()
{
	int arr[]={10, 12, 8, 17, 25, 35, 19};
	int size=sizeof(arr)/sizeof(int);

	int res=third_largest(arr, size);
	printf("Third largest is %d\n",res);
	return 0;
}