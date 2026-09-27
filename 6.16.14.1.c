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
        b[0]=a[0];
        b[n]=b[n-1]+a[n];
    }
    for(n=0;n<8;n++)
    {
        printf("%lf ",a[n]);
        printf("%lf \n",b[n]);
    }
    return 0;
}