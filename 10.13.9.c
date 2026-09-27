#include<stdio.h>
void copy_arr2(int a,int b,double target1[a][b],double source[a][b]);
void copy_arr(double target1[],double source[], int n);
void printf_2(int a,int b,double con[a][b]);
void printf_(int b,double con[b]);

int main (void)
{
    double source[3][5] = {{1.1, 2.2, 3.3,4,5}, {4.4, 5.5,6.6,7,8},{1,2,3,4,5}};
    double target1[3][5];
    copy_arr2(3,5,target1, source);
    printf_2(3,5,source);
    printf_2(3,5,target1);
}

void copy_arr(double target1[],double source[], int n)
{
    int n1;
    for (n1 = 0;n1<n;n1++)
    {
        target1[n1] = source[n1];
    }
}

void copy_arr2(int a,int b,double target1[a][b],double source[a][b])
{
    int n1,n2;
    for (n1=0;n1<a;n1++)
    {
        copy_arr(target1[n1],source[n1],b);
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