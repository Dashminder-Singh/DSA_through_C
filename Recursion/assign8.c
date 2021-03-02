#include <stdio.h>

int even(int n)
{
	if(n==1)
		return 2;
	return  even(n-1)+ n*2;
}

int main()
{
	int ans;
	ans=even(3);
	printf("Sum of even: %d\n",ans);
	return 0;
}