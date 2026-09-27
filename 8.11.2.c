#include<stdio.h>
int main(void)
{
    char get;
    int width=0;
    while( (get = getchar()) != EOF)
    {
        
        if (get >= ' ')
        printf("%c,%d ",get,get);
        else 
        printf("^%c,%d ",get+64,get);
        if (width % 10 == 0)
            printf("\n");
        width++;
    }
    return 0;
}