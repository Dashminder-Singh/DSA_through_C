#include <stdio.h>

int fib(int n)
{
	if(n==0 || n==1)
		return n;
	return fib(n-1)+ fib(n-2);
}

int main()
{
	printf("nth term is %d ",fib(6));
	return 0;
}