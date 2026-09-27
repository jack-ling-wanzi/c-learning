#include<stdio.h>
void copy_ptrs(double target3[],double source[], double * source5);

void printf_(int b,double con[b]);

int main (void)
{
    double source[7] = {1.1, 2.2, 3.3, 4.4, 5.5,6.6,7.7};

    double target3[3];

    copy_ptrs(target3, source+2, source + 5);

    printf_(7,source);

    printf_(3,target3);
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