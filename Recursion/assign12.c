#include <stdio.h>

void DtoB(int n)
{
	if(n==1)
	{
		printf("1 ");
	}
	else
	{
		DtoB(n/2);
		printf("%d ",n%2);
	}
}

int main()
{
	DtoB(12);
	return 0;
}