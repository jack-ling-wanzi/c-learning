#include<stdio.h>
int main(void)
{
    int n;
    char con[255];
    for (n=0;n<=255;n++)
    {
        scanf("%c",&con[n]);

    }
    for (printf("dao:"),n=0;n<=255;n++)
    {

        printf("%c",con[n]);

    }
    return 0;
}