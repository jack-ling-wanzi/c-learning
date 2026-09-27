#include<stdio.h>
int main(void)
{
    char get;
    int num=0;
    while( (get = getchar()) != EOF)
    {
        num++;
    }
    printf("zifushuo:%d",num);
    return 0;
}