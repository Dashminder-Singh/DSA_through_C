#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);

	int k;
	for(int i=1; i<=n; i++)
	{
		k=1;
		while(k!=i)
		{
			printf(" ");
			k++;
		}
		for(int j=i; j<=n; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}