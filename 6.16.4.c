#include<stdio.h>
int main(void)
{
    int n,i,a;
    for (n = 'A',i=1;i<=10;i++)
    {
        for (a=0;a!=i;a++,n++)
        printf("%c",n);
        printf("\n");
    }      
    return 0;
}