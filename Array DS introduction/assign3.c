#include <stdio.h>

void print_frequnecy(int A[], int N, int freq[])
{
	int count, i, j;

	for(i=0; i<N; i++)
	{
		count=1;
		for(j=i+1; j<N; j++)
		{
			if(A[i]==A[j])
			{
				count++;
				freq[j]=0;
			}
		}
		if(freq[i]!=0)
		{
			freq[i]=count;
		}
	}

	for(i=0; i<N; i++)
	{
		if(freq[i]!=0)
		{
			printf("%d occur %d times\n",A[i], freq[i]);
		}
	}
}

int main()
{
	int arr[]={1, 2, 3, 5, 3 ,2 ,9 ,7 ,6};
	int size=sizeof(arr)/sizeof(int);

	int freq[size];

	for(int i=0; i<size; i++)
	{
		freq[i]=-1;
	}

	print_frequnecy(arr,size, freq);
	return 0;
}