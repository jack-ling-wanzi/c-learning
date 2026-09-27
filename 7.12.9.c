#include<stdio.h>
int main(void)
{
    _Bool judge;
    unsigned int max,zhi,count,n;
    while(scanf("%u",&max))
    {
        zhi = 0;n = 2;
    while(n<=max)
    {
        judge = 1;
        for (count=2;count*count<=n;count++)
        {
            if(n%count==0)
            {
                judge=0;break;
            }
            else judge=1;
        }
        if (judge)
        {
            zhi++;
            printf("%u ",n);
        }
        n++;
    }
    printf("zhishuo:%u\n",zhi);
    }
    return 0;
}