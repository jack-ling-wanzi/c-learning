#include<stdio.h>
double min(double,double);
int main(void)
{
    double x,y;
    while(scanf("%lf %lf",&x,&y))
    {
    printf("the smaller of %lf and %lf is %lf.\n",x,y,min(x,y));
    }
    return 0;
}
double min(double x,double y)
{
    return x<y?x:y;
}