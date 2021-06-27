#include <stdio.h>

void Merge(int arr[], int l, int mid, int u)
{
	int n1,n2;
	n1=mid-l+1;
	n2=u-mid;

	int A[n1], B[n2];

	for(int i=0; i<n1; i++)
	{
		A[i]=arr[l+i];
	}
	for(int j=0; j<n2; j++)
	{
		B[j]=arr[mid+1+j];
	}

	int i, j,k;
	i=j=0;
	k=l;

	while(i<n1 && j<n2)
	{
		if(A[i]<B[j])
		{
			arr[k]=A[i];
			i++;
			k++;
		}
		else
		{
			arr[k]=B[j];
			j++;
			k++;
		}
	}
	while(i<n1)
	{
		arr[k]=A[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k]=B[j];
		j++;
		k++;
	}
}

void Merge_sort(int arr[], int l, int u)
{
	int mid;
	mid=(l+u)/2;
	if(l<mid)
	{
		Merge_sort(arr,l, mid);
	}
	if(mid+1<u)
	{
		Merge_sort(arr, mid+1, u);
	}
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
	return 0;
}