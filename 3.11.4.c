#include<stdio.h>
int main(void)
{
    float a;
    printf("Enter a floating-point:");
    scanf("%f",&a);
    printf("fixed-point notation:%f,\nexponential notation:%e,\np natation:%a",a,a,a);
    return 0;
}