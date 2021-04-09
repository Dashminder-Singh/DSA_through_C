#include <stdio.h>
#include <string.h>

void permutation(char s[], int i, int j)
{
	char ch;
	static int count;
	int x;

	if(i==j)
		printf("%d) %s\n", ++count,s);
	else
	{
		for(x=i; x<=j; x++)
		{
			ch=s[i];
			s[i]=s[x];
			s[x]=ch;

			permutation(s, i+1, j);

			ch=s[i];
			s[i]=s[x];
			s[x]=ch;
		}
	}
}

int main()
{
	char str[]="ABC";
	permutation(str, 0, strlen(str)-1);
	return 0;
}