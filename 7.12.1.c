#include <stdio.h>
#include <ctype.h>
int main(void)
{
    char a;
    int sp=0,hh=0,qt=0;
    while((a=getchar())!='#')
    {
        if (a == ' ')
            sp++;
        else if (a == '\n')
            hh++;
        else
            qt++;
        
    }
    printf("sp:%d,hh:%d,qt:%d",sp,hh,qt);
    
}