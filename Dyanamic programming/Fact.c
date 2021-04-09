#include <stdio.h>

int factorial(int n)
{
	if(n==1)
		return n;
	return factorial(n-1)* n;
}

int main()
{
	printf("%d ",factorial(5));
	return 0;
}