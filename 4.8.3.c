#include<stdio.h>
int main(void)
{
    double f;
    printf("input a number:");
    scanf("%lf",&f);
    printf("The input is %f or %e.",f,f);
    
    return 0;
}