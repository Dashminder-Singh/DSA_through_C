#include <stdio.h>

int Quick(int arr[],int l, int u)
{
	int loc, left, right, temp;
	left=loc=l;
	right=u;

	while(left<right)
	{
		while(arr[loc]<arr[right])
			right--;
		temp=arr[loc];
		arr[loc]=arr[right];
		arr[right]=temp;
		loc=right;

		while(arr[left]<arr[loc])
			left++;
		temp=arr[loc];
		arr[loc]=arr[left];
		arr[left]=temp;
		loc=left;

		if(left==right)
			break;
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

int main()
{
	int arr[]={50, 20, 100, 80, 120, 90, 60, 10, 30, 70, 40, 110, 150, 140, 130};

	//int arr[]={50, 11, 25, 8, 6, 36, 20, 18};

	Quick_sort(arr,0,14);	
	for(int i=0; i<=14; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}