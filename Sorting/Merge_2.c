#include <stdio.h>

void Merge(int A[], int l, int m, int u)
{
	int i,j,k, C[50];
	i=l;
	j=m+1;
	k=l;

	while(i<=m && j<=u)
	{
		if(A[i]<A[j])
		{
			C[k]=A[i];
			k++; 
			i++;
		}
		else
		{
			C[k]=A[j];
			k++;
			j++;
		}
	}

	while(i<=m)
	{
		C[k]=A[i];
		k++; 
		i++;
	}
	while(j<=u)
	{
		C[k]=A[j];
		k++; 
		j++;
	}

	for(int s=l; s<=u; s++)
	{
		A[s]=C[s];
	}
}

void Merge_sort(int arr[], int l, int u)
{
	int mid;
	mid=(l+u)/2;
	if(l<mid)
		Merge_sort(arr,l,mid);
	if(mid+1<u)
		Merge_sort(arr,mid+1,u);
	Merge(arr,l,mid,u);
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
	int arr[]={50, 20, 100, 80, 120, 90, 60, 10, 30, 70, 40, 110, 150, 140, 130};

	Merge_sort(arr,0,14);
	display(arr,15);
	printf("\n");
	return 0;
}