#include <stdio.h>

void reverse(int n)
{
	if(n/10==0)
	{
		printf("%d", n);
	}
	else
	{
		printf("%d ", n%10);
		reverse(n/10);
	}
}

int main()
{
	reverse(1234);
	return 0;
}