#include <stdio.h>
#include <stdlib.h>

int delete_from_heap(int Heap[], int *hs)
{
	int item,temp, leftindex, rightindex,index;
	item=Heap[0];
	temp=Heap[*hs-1];
	*hs=*hs-1;

	index=0;

	while(index<*hs)
	{
		leftindex=2*index+1;
		rightindex=2*index+2;

		if(leftindex>*hs-1) // 0 child
		{
			break;
		}
		if(rightindex>*hs-1)  // only left child
		{
			if(temp<Heap[leftindex])
				Heap[index]=Heap[leftindex];
			else
				break;
			index=leftindex;
		}

		if(Heap[leftindex]>Heap[rightindex])
		{
			if(temp<Heap[leftindex])
				Heap[index]=Heap[leftindex];
			else
				break;
			index=leftindex;
		}
		else
		{
			if(temp<Heap[rightindex])
				Heap[index]=Heap[rightindex];
			else
				break;
			index=rightindex;
		}
	}
	Heap[index]=temp;
	return item;
}

void insert_heap(int Heap[], int *hs, int data)
{
	int index, parindex;

	*hs=*hs+1;
	index=*hs-1;

	while(index>0)
	{
		parindex=(index-1)/2;
		if(data> Heap[parindex])
			Heap[index]=Heap[parindex];
		else
			break;
		index=parindex;
	}
	Heap[index]=data;
}

void heap_sort(int Heap[],int size,int *hs)
{
	int data;
	while(size>0)
	{
		data=delete_from_heap(Heap,hs);
		size--;
		Heap[size]=data;
	}
}

int main()
{
	int arr[]={100, 20, 90, 150, 70, 30, 10, 140, 80, 120, 40, 60, 110, 50, 130};

	int Heap[100], heapsize=0, size=15, data;

	for(int i=0; i<size; i++)
	{
		insert_heap(Heap, &heapsize, arr[i]);
	}

	for(int i=0; i<heapsize; i++)
	{
		printf("%d ",Heap[i]);
	}
	printf("\n");

	heap_sort(Heap,size,&heapsize);

	printf("\nHeap is sorted: \n");

	for(int i=0; i<size; i++)
	{
		printf("%d ",Heap[i]);
	}
	printf("\n");

	return 0;
}