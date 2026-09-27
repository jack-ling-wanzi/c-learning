#include<stdio.h>
int main(void)
{
    int a;
    float b;
    printf("input the number:");
    scanf("%d",&a);
    b=a * 950 / 3.0e-23;
    printf("the numer is %f",b);
    return 0;
}