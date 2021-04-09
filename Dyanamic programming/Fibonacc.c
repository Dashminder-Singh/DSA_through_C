#include <stdio.h>

int Fib(int n)
{
	if(n==0 || n==1)
		return n;
	return Fib(n-1)+Fib(n-2);
}

int main()
{
	printf("%d",Fib(6));

	/*int ans;
	for(int i=0; i<6; i++)
	{
		ans=Fib(i);
		printf("%d ",ans);
	}*/
	return 0;
}