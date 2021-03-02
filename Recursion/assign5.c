#include <stdio.h>

void odd(int n)
{
	if(n>=1)
	{
		odd(n-1);
		printf("%d ",2*n-1);
	}
}

int main()
{
	odd(5);
	return 0;
}