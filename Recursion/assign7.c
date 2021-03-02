#include <stdio.h>

int sum(int n)
{
	if(n==1)
		return n;
	return sum(n-1)+ n;
}

int main()
{
	int ans;
	ans=sum(3);
	printf("Sum of n is: %d\n", ans);
	return 0;
}