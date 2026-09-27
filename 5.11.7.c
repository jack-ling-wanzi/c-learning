#include<stdio.h>
void jisuan(double n);
int main()
{
    double n;
    printf("input");
    scanf("%lf",&n);
    jisuan(n);
    return 0;
}
void jisuan(double n)
{
    printf("%f",n*n);
}