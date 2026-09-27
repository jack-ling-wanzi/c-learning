#include<stdio.h>
#include<iso646.h>
void max(double*,double*,double*);
void exchange(double*,double*);
int main(void)
{
    double x,y,z;
    while(printf("input the value of x,y and z\n"),scanf("%lf %lf %lf",&x,&y,&z))
    {

        max(&x,&y,&z);
        printf("(x=%lf) < (y=%lf) < (z=%lf)\n",x,y,z);
    }
    return 0;
}
void max(double * x,double * y,double * z)
{
    double temp1,temp2;
    while (*x>*y or *y>*z)
    {
        if(*x > *y)
        {
        exchange(x,y);
        }
        if(*y > *z)
        {
        exchange(y,z);
        }
    }
}
void exchange(double * x,double * y)
{
    double temp;
    temp = *x;
    *x = *y;
    *y = temp;
}