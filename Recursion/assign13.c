#include <stdio.h>

void DtoO(int n)
{
	if(n>0)
	{
		DtoO(n/8);
		printf("%d ",n%8);
	}
}

int main()
{
	DtoO(25);
	return 0;
}