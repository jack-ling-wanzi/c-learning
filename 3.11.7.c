#include<stdio.h>
int main(void)
{
    float inch,cm;
    printf("input height:");
    scanf("%f",&inch);
    cm = inch * 2.54;
    printf("the height is %f cm.",cm);
}