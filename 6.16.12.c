#include<stdio.h>
int main(void)
{
    unsigned long int max;
    double n,sum;
    while(1){
    for (n=1.0,sum = 0.0,scanf("%u",&max);n<=max;n++)
    {
        sum += 1.0 / n;
    }
    printf("the sum is %lf.\n",sum);
    }
    return 0;
}