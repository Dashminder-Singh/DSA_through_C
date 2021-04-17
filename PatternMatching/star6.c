#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int k;
	for(int i=1; i<=n; i++)
	{
		k=0;
		while(k!=n-i)
		{
			printf(" ");
			k++;
		}
		for(int j=1; j<=(2*i)-1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}