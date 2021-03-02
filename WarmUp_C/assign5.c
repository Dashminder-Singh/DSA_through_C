#include <stdio.h>

struct Temp
{
	int min;
	int max;
};

void input(struct Temp t[],int days)
{
	for(int i=0; i<days; i++)
	{
		printf("Enter a max_temp & min_temp of %d day: ",i+1);
		scanf("%d",&t[i].max);
		scanf("%d",&t[i].min);
	}
	printf("\n");
}

int min_avg(struct Temp d1[],int days)
{
	int sum=0;
	for (int i=0; i<days; i++)
	{
		sum=sum + d1[i].min;	
	}
	return (sum/days);
}

int max_avg(struct Temp d2[],int days)
{
	int sum=0;
	for(int i=0; i<days; i++)
	{
		sum= sum + d2[i].max;
	}
	return (sum/days);
}

int main()
{
	int n;
	printf("Enter No of days: ");
	scanf("%d",&n);
	struct Temp t[n];
	input(t,n);
	
	int min_temp=min_avg(t,n);
	int max_temp=max_avg(t,n);

	printf("The Avarage Minimum Tempreature of %d days= %d\n",n,min_temp);
	printf("The Avarage Maximum Tempreature of %d days= %d\n",n,max_temp);
	return 0;
}
