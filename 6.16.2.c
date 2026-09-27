#include<stdio.h>
int main(void)
{
    int n,i;
    for (n=1;n<=5;n++,printf("\n"))
        for (i=0;i!=n;printf("$"),i++);
        
    return 0;
}