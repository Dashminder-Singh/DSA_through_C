#include <stdio.h>

int main() 
{
    int n;
    scanf("%d", &n);
    int min;
    int len = n*2 - 1;
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            min = i < j ? i : j;
            min = min < len-i ? min : len-i-1;
            min = min < len-j-1 ? min : len-j-1;
            printf("%d ", n-min);
        }
        printf("\n");
    }
    return 0;
}

/*
2 input

2 2 2
2 1 2
2 2 2
*/