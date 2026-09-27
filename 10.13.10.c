#include<stdio.h>
void sum(double *p1,double *p2,double *p3,int num);
void printf_(int b,double con[b]);
int main(void)
{
    double a[5] = {1,2,5,9,6},b[5]={1,9,8,4,7},c[5];
    sum(a,b,c,5);
    printf_(5,c);
}

void sum(double *p1,double *p2,double *p3,int num)
{
    int n;
    for(n = 0;n<num;n++)
    {
        p3[n] = p1[n] + p2[n];
    }
}
void printf_(int b,double con[b])
{
    int m;
        for (m = 0;m<b;m++)
        {
            printf("%lf ",con[m]);
        }
        printf("\n");
    
}