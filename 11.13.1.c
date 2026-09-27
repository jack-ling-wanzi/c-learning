#include<stdio.h>
char * get_x(char * a,int x);
void printf_(int b,char con[b]);
int main(void)
{
    char p[9];
    char * q = p;
    q = get_x(p,9);
    printf_(9,p);
    return 0;
}

char * get_x(char *a,int x)
{
    int n;
    char * b;
    b = a;
    for (n=0;n<x;n++,b++)
    {
        *b = getchar();
    }
    while(getchar()!='\n');
    return a;
}

void printf_(int b,char con[b])
{
    int m;
        for (m = 0;m<b;m++)
        {
            printf("%c ",con[m]);
        }
        printf("\n");
}