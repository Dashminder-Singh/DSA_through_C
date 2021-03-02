#include <stdio.h>
#include <stdlib.h>

int * new_arr(int arr[], int n)
{
	int *A;
	A=(int *)malloc(n * sizeof(int));

	for(int i=0; i<n; i++)
	{
		*(A+i)=arr[i];
	}
	return A;
}

int main()
{
	int arr1[]={5, 11, 8};
	int arr2[]={10, 7, 4};

	int m= sizeof(arr1)/sizeof(int);
	int n= sizeof(arr2)/sizeof(int);

	int arr3[m+n];

	int count=0;
	for(int i=0; i<m; i++)
	{
		arr3[count]=arr1[i];
		count++;
	}

	for(int i=0; i<n; i++)
	{
		arr3[count]=arr2[i];
		count++;
	}

	int *a;
	a=new_arr(arr3, m+n);
	for(int i=0; i<(m+n); i++)
	{
		printf("%d ",*(a+i));
	}

	return 0;
}