#include <stdio.h>

int sumof_digit(int n)
{
	if(n/10==0)
		return n;
	return sumof_digit(n/10)+ n%10;
}

int main()
{
	int ans;
	ans=sumof_digit(1234);
	printf("Sum of digit: %d\n", ans);
	return 0;
}