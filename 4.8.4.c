#include<stdio.h>
int main(void)
{
    float f;
    char n[20];
    printf("input your height(inch):");
    scanf("%f",&f);
    printf("input your name:");
    scanf("%s",n);
    f = f / 12;
    printf("%s,Tyou are %f feet tall",n,f);
    
    return 0;
}