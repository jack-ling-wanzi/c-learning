#include<stdio.h>
int main(void)
{
    int num[8],n;
    printf("input 8 numbers:");
    for(n=0;n<=7;n++)
    {
        scanf("%d",&num[n]);
    }
        printf("upsid down:");
    for(n=7;n>=0;n--)
    {
        printf("%d ",num[n]);
    }
    return 0;
}