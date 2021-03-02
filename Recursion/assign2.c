#include <stdio.h>

void first_n_reverse(int n)
{
	if(n>=1)
	{
		printf("%d ", n);
		first_n_reverse(n-1);
	}
}

int main()
{
	first_n_reverse(5);
	return 0;
}