#include <stdio.h>

int Binary_search(int arr[], int l, int u, int data)
{
	int mid;
	while(l<=u)
	{
		mid=(l+u)/2;
		if(arr[mid]==data)
			return mid;
		if(data<arr[mid])
			u=mid-1;
		else
			l=mid+1;
	}
	return -1;
}

int main()
{
	int arr[]={10, 20, 30, 40 ,45, 50, 68, 79};

	int res=Binary_search(arr,0,7,20);
	if(res!=-1)
		printf("%d found at %d index\n",arr[res],res);
	else
		printf("Not found\n");
	return 0;
}