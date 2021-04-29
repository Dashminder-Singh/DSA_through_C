#include <stdio.h>

long long toh(int n, int from, int to, int aux)
{
	long long count=0;
	if(n>0)
	{
		count+=toh(n-1, from, aux, to);
		printf("moves disk %d from rod %d to  rod %d\n",n, from, to);
		++count;
		count+=toh(n-1,aux,to, from);
	}
	return count;
}

int main()
{
	int T;
	scanf("%d",&T);

	while(T--)
	{
		int n;
		long long moves=0;
		scanf("%d",&n);
		moves=toh(n,1, 3, 2);
		printf("%ld\n",moves);
	}
	

	return 0;
}