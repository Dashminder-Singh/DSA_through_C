#include <stdio.h>

void odd_reverse(int n)
{
	if(n>=1)
	{
		printf("%d ",2*n-1);
		odd_reverse(n-1);
	}
}

int main()
{
	odd_reverse(5);
	return 0;
}