#include <stdio.h>

int F[20];

int fib(int n)
{
	if(F[n]!=-1)
	{
		return F[n];
	}
	if(n==0 || n==1)
		F[n]=n;
	else
		F[n]=fib(n-1)+fib(n-2);
	return F[n];
}

int main()
{
	for(int i=0; i<20; i++)
	{
		F[i]=-1;
	}

	for(int i=0; i<=6; i++)
	{
		printf("%d ",fib(i));
	}
	return 0;
}