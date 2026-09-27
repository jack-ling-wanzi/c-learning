#include<stdio.h>
int main(void)
{
    int jh = 0,gt = 0;
    char get;
    while ((get = getchar()) != '#')
    {
        switch(get)
    {
        case '.':
        jh++;
        putchar('.');
        continue;
        case '!':
        gt++;
        putchar('!');
        putchar('!');
        continue;
        default:
        putchar(get);
    }
    }
    printf("gt:%d,jh:%d.\n",gt,jh);
    return 0;

}