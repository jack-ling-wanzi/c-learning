#include<stdio.h>
void x_times(double *p1,int num,int x);
void x_times2(int a,int b,double p1[a][b],int x);
void printf_(int b,double con[b]);
void printf_2(int a,int b,double con[a][b]);
int main(void)
{
    double a[5] = {1,2,5,9,6},b[5]={1,9,8,4,7},c[5];
    double source[3][5] = {{1.1, 2.2, 3.3,4,5}, {4.4, 5.5,6.6,7,8},{1,2,3,4,5}};
    x_times2(3,5,source,2);
    printf_2(3,5,source);
}

void x_times(double *p1,int num,int x)
{
    int n;
    for(n = 0;n<num;n++)
    {
        p1[n] *= x;
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
void printf_2(int a,int b,double con[a][b])
{
    int m,n;
        for (m = 0;m<a;m++)
        {
            printf_(b,con[m]);
        }
        printf("\n");
}
void x_times2(int a,int b,double p1[a][b],int x)
{
    int n;
    for(n = 0;n<a;n++)
    {
        x_times(p1[n],b,x);
    }
}