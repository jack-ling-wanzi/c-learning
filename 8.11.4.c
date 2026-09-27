#include<stdio.h>
#include<iso646.h>
#include<ctype.h>
int main(void)
{
    char get;
    int letter = 0;
    while( (get = getchar()) != EOF)
    {
        if (isalpha(get))
        {
            while(isalpha(getchar()))
            ;
            letter++;
        }
    }
    printf("letter:%d",letter);
    return 0;
}