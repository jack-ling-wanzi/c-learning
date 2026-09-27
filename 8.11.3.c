#include<stdio.h>
#include<iso646.h>
int main(void)
{
    char get;
    int small=0,big=0;
    while( (get = getchar()) != EOF)
    {
        if (get <='z' && get >='a')
        {
            small++;
        }
        else if(get >= 'A' && get <= 'Z')
        {
            big++;
        }
    }
    printf("daxie:%d,xiaoxie:%d",big,small);
    return 0;
}