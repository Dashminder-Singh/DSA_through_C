#include <stdio.h>

int sum_of_squ(int n)
{
	if(n==1)
		return 1;
	return sum_of_squ(n-1)+ n*n;
}

int main()
{
	int ans;
	ans=sum_of_squ(3);
	printf("Sum of square: %d\n", ans);
	return 0;
}