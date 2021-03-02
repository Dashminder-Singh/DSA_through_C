#include <stdio.h>

void TOH(int n, char beg, char aux, char end)
{
	static int count;
	if(n>0)
	{
		TOH(n-1,beg, end, aux);
		printf("%d %c->%c\n",++count,beg,end);
		TOH(n-1, aux, beg, end);
	}
}

int main()
{
	TOH(3,'A','B','C');
	return 0;
}