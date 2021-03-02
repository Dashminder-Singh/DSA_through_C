#include <stdio.h>

void first_n(int n)
{ 
	if(n>=1)
	{
		first_n(n-1);
		printf("%d ",n);
	}
}

int main()
{
	first_n(5);
	return 0;
}