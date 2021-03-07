#include <stdio.h>

int Quick(int arr[],int l, int u)
{
	int loc, left, right,temp;
	loc=left=l;
	right=u;

	while(left<right)
	{
		while(arr[loc]<arr[right])
			right--;
		if(left==right)
			break;
		else
		{
			temp=arr[loc];
			arr[loc]=arr[right];
			arr[right]=temp;
			loc=right;
		}

		while(arr[left]<arr[loc])
			left++;
		if(left==right)
			break;
		else
		{
			temp=arr[loc];
			arr[loc]=arr[left];
			arr[left]=temp;
			loc=left;
		}
	}
	return loc;
}

void Quick_sort(int arr[], int l, int u)
{
	int loc;
	loc=Quick(arr,l,u);
	if(l<loc-1)
		Quick_sort(arr,l,loc-1);
	if(loc+1<u)
		Quick_sort(arr,loc+1,u);
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
	int n;
	printf("Enter how many: ");
	scanf("%d",&n);
	int arr[50];

	printf("Enter %d values: ", n);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	Quick_sort(arr,0,n-1);
	display(arr,n);
	printf("\n");
	return 0;
}