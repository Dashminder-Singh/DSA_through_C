#include <stdio.h>

int Binary_search(int arr[], int l, int u, int data)
{
	int mid;
	if(l<=u)
	{
		mid=(l+u)/2;
		if(arr[mid]==data)
			return mid;
		if(data<arr[mid])
			return Binary_search(arr,l,mid-1,data);
		else
			return Binary_search(arr,mid+1,u,data);
	}
	return -1;
}

int main()
{
	int arr[]={10, 15, 20, 25, 35, 45, 55, 65, 78};

	int res=Binary_search(arr,0,8,35);
	if(res!=-1)
		printf("%d found at %d index\n",arr[res],res);
	else
		printf("Not found\n");
	return 0;
}