#include<stdio.h>
void max(double*,double*);
int main(void)
{
    double x,y;
    while(scanf("%lf %lf",&x,&y))
    {
        max(&x,&y);
        printf("%lf %lf",x,y);
    }
    return 0;
}
void max(double * x,double * y)
{
    double temp;
    temp = *x>*y?*x:*y;
    *x=temp;
    *y=temp;
}