#include<stdio.h>

int main(int argc,char **argv)
{
    char *string[argc],*temp;
    int n1,n2,n3,n4;

    for(n1=0;n1<argc;n1++)
    {
        string[n1] = argv[n1];
    }

    for(n2=1,n3=argc-1;n2<=n3;n2++,n3--)
    {
        temp = string[n2];
        string[n2] = string[n3];
        string[n3] = temp;
    }

    for(n4=1;n4<argc;n4++)
    puts(string[n4]);

    return 0;
    
}