#include <stdio.h>

void Merge(int A[],int B[],int C[],int m, int n)
{
	int i,j,k;
	i=j=k=0;

	while(i<m && j<n)
	{
		if(A[i]<B[j])
		{
			C[k]=A[i];
			k++;
			i++;
		}
		else
		{
			C[k]=B[j];
			k++;
			j++;
		}
	}
	while(i<m)
	{
		C[k]=A[i];
		k++;
		i++;
	}
	while(j<n)
	{
		C[k]=B[j];
		k++;
		j++;
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
	int C[20];

	int A[5]={7, 9, 18, 19, 25};
	int B[4]={1, 6, 9, 12};

	Merge(A,B,C,5,4);
	display(C,9);

	return 0;
}