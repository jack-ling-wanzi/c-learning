#include<stdio.h>
int main(void)
{
    int n,n1;
    double a[8],b[8],sum;
    for(n=0;n<8;n++)
    {
        scanf("%lf",&a[n]);
    }
    for(n=0;n<8;n++)
    {
        for(sum=0,n1=0;n1<=n;n1++)
        {
            sum+=a[n1];
        }
        b[n]=sum;
    }
    for(n=0;n<8;n++)
    {
        printf("%lf ",a[n]);
        printf("%lf \n",b[n]);
    }
    return 0;
}