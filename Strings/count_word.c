#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *remove_space(char *s)
{
	char *p;
	p=(char *)malloc(sizeof(char)* strlen(s+1));

	int i=0, j=0;

	while(s[i]!='\0')
	{
		while(s[i]==' ')
		{
			i++;
		}
		while(s[i]!='\0'  && s[i]!=' ')
		{
			p[j]=s[i];
			j++;
			i++;
		}
		if(s[i]=='\0'  && p[j-1]==' ')
		{
			j--;
		}
		p[j]=s[i];
		j++;
	}

	return p;
}

int count(char *str)
{
	int i=0, count=0;
	while(str[i]!='\0')
	{
		if(str[i]==' ')
		{
			count++;
		}
		i++;
	}
	return count+1;
}
int main()
{
	char exp[]="one two  ";

	strcpy(exp,remove_space(exp));
	printf("Words: %d\n",count(exp));

	return 0;
}