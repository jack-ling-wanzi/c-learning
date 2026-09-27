#include<stdio.h>
double invert(double * p,int num);
void printf_(int b,double con[b]);
int main(void)
{
    double numbers[9] = {5,4,3,8,6,1,7,9,2};
    printf_(9,numbers);
    invert(numbers,9);
    printf_(9,numbers);
    return 0;
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

double invert(double * p,int num)
{
    int n1,n2;
    double temp;
    for(n1=num-1,n2=0;n1>=n2;n1--,n2++)
    {
        temp=p[n1];
        p[n1]=p[n2];
        p[n2]=temp;
    }
    return 0;
}