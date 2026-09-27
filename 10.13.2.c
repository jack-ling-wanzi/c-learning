#include<stdio.h>
void copy_arr(double target1[],double source[], int n);
void copy_ptr(double * target2,double * source, int n);
void copy_ptrs(double target3[],double source[], double * source5);

void printf_(int b,double con[b]);

int main (void)
{
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];

    copy_arr(target1, source, 5);
    copy_ptr(target2, source, 5);
    copy_ptrs(target3, source, source + 5);

    printf_(5,source);
    printf_(5,target1);
    printf_(5,target2);
    printf_(5,target3);
}

void copy_arr(double target1[],double source[], int n)
{
    int n1;
    for (n1 = 0;n1<n;n1++)
    {
        target1[n1] = source[n1];
    }
}

void copy_ptr(double * target2,double * source, int n)
{
    int n1;
    for (n1 = 0;n1<n;n1++)
    {
        *(target2+n1) = *(source+n1);
    }
}

void copy_ptrs(double target3[],double source[], double * sourceend)
{
    double * p, * sp;
    int n1;
    p = target3;
    sp = source;
    for (n1 = 0;sp<sourceend;sp++,n1++)
    {
        target3[n1] = source[n1];
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