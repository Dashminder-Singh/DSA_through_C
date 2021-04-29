#include <stdio.h>

void bellNumber(int n)
{
  int k, bell;
  bell=1;
  for (int i=1; i<=n; i++)
  {
    for (int j=1; j<=i; j++)
	  {
      if(i>1 && j==1)
      {
        printf("%d ",bell);
      }
      else if(i%2==0 && i>2) 
      {
        k=i-j+bell;
        printf("%d ",k);
        bell=k;
      }
      else
      {
        k=j-1+bell;
        printf("%d ",k);
        bell=k;
      }  
		}
    printf("\n");
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	bellNumber(n);
	return 0;
}
