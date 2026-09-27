#include<stdio.h>
int main(void)
{
    int a,b;
    printf("input number:");
    scanf("%d",&a);
    b = a;
    while (a<=b+10)
    {
        printf("%5d",a);
        a++;
        
    }
    return 0;
}