#include <stdio.h>

int main()
{
	int n,k;
	scanf("%d",&n);

	for(int i=n; i>=1; i--)
	{
		k=0;
		while(k!=n-i)
		{	
			printf(" ");
			k++;
		}
		for(int j=1; j<=2*i-1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}