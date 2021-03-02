#include <stdio.h>

int odd(int n)
{
	if(n==1)
		return 1;
	return 2*n-1 + odd(n-1);
}

int main()
{
	int ans;
	ans=odd(2);
	printf("Sum of odd: %d\n",ans);
	return 0;
}