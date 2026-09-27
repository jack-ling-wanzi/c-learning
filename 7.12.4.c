#include<stdio.h>
int main(void)
{
    char get;
    int jh=0,gt=0;
    while((get = getchar()) != '#')
    {
        if (get == '.')
        {
            putchar('!');
            jh++;
        }
        else if (get == '!')
        {
            putchar('!');
            putchar('!');
            gt++;
        }
        else putchar(get);
    }
    printf("gt:%d,jh:%d.\n",gt,jh);
    return 0;
}