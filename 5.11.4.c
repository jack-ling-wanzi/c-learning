#include<stdio.h>
int main(void)
{
    float cm,left,inch;
    int n= 0;
    printf("input:");
    scanf("%f",&cm);
    inch = cm *0.39370079;
    while(((n+1)*12)<=inch)
    {
        n++;
        
        
    }
    left = inch - n *12;
    printf("%f cm is %d feet and %f inch",cm,n,left);

}