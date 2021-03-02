#include <stdio.h>

void even_reverse(int n)
{
	if(n>=1)
	{
		printf("%d ",2*n);
		even_reverse(n-1);
	}
}

int main()
{
	even_reverse(5);
	return 0;
}