#include<stdio.h>
int main(void)
{
    int n = 1;
    char get;
    while ((get=getchar()) != '#' )
    {
        putchar(get);
        printf("%c ",get);
        if ((n%8) == 0)
            printf("\n");
        n++;
    }
}