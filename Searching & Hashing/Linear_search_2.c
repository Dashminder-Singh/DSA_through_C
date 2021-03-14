#include <stdio.h>

int Linear_search(int arr[],int index,int N,int data)
{
	if(index<N)
	{
		if(arr[index]==data)
			return index;
		return Linear_search(arr,index+1,N,data);
	}
	return -1;
}

int main()
{
	
	int arr[]={8, 0, 7, 1, 3, 5, 11 ,18};
	int size=sizeof(arr)/sizeof(int);

	int res=Linear_search(arr,0,size,1);

	if(res!=-1)
		printf("%d Found at %d index\n",arr[res],res);
	else
		printf("Not found\n");
	return 0;
}