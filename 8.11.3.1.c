#include<stdio.h>
#include<iso646.h>
#include<ctype.h>
int main(void)
{
    char get;
    int small=0,big=0;
    while( (get = getchar()) != EOF)
    {
        if (islower(get))
        {
            small++;
        }
        else if(isupper(get))
        {
            big++;
        }
    }
    printf("daxie:%d,xiaoxie:%d",big,small);
    return 0;
}