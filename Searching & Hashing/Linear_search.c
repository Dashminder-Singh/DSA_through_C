#include <stdio.h>

int Linear_search(int arr[],int N, int data)
{
	int index;
	for(index=0; index<N; index++)
	{
		if(arr[index]==data)
			return index;
	}
	return -1;
}

int main()
{
	int arr[]={8, 11, 15, 3, 0, 7, 25, 36, 19};
	int size=sizeof(arr)/sizeof(int);

	int res=Linear_search(arr,size,36);
	if(res!=-1)
		printf("%d found at %d index\n",arr[res],res);
	else
		printf("Not found\n");
	return 0;
}