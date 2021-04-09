#include <stdio.h>

void rotate(int A[], int N, int d, int dir)
{
	int temp;
	if(dir==1)
	{
		while(d!=0)
		{
			temp=A[N-1];
			for(int i=N-1; i>0; i--)
			{
				A[i]=A[i-1];
			}
			A[0]=temp;
			d--;
		}
	}
	else
	{
		while(d!=0)
		{
			temp=A[0];
			for(int i=0; i<N-1; i++)
			{
				A[i]=A[i+1];
			}
			A[N-1]=temp;
			d--;
		}
	}
}

void display(int A[], int N)
{
	for(int i=0; i<N; i++)
	{
		printf("%d ",A[i]);
	}
	printf("\n");
}

int main()
{
	int arr[]={10, 20, 30, 40, 50, 60};
	int size=sizeof(arr)/sizeof(int);

	rotate(arr,size,2,1);
	display(arr,size);
	return 0;
}