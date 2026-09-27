#include<stdio.h>

void Temp(double n);

int main(void)
{
    double a;
    while (scanf("%lf",&a) == 1)
    {
        Temp(a);
    }
    return 0;
}
void Temp(double n)
{
    double s,h,k;
    h=n;s=5.0/9.0*(h - 32.0);k=s+273.16;
    printf("s:%lf,h:%lf,k:%lf",s,h,k);
}