#include<stdio.h>
int main(void)
{
    int ei=0;
    char get,get1;
    while((get = getchar()) !='#')
    {
        if (get == 'e')
        {
            get1 = getchar();
            if(get1 == 'i')
            {
                ei++;
            }
        }
    }
    printf("ei:%d",ei);
    return 0;
}