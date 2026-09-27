#include<stdio.h>
int main(void)
{
    int a = 2147483648;
    float b = 3.4e38;
    float c = 10.0/3;
    printf("%d %f %f",a,b,c/100);
    return 0;
}