#include <stdio.h>

int main()
{
	int n;
	printf("Enter the value of (n): ");
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=i; j++)
		{
			printf("%c",(char)(j+64));  // Ascii value A=65, a=97
		}
		printf("\n");
	}
	return 0;
}