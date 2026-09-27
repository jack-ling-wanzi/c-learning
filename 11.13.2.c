#include<stdio.h>
char * get_x(char * a,int x);
void printf_(int b,char con[b]);
int main(void)
{
    char p[9]={0};
    char * q = p;
    q = get_x(p,9);
    printf_(9,p);
    return 0;
}

char * get_x(char *a,int x)
{
    char ch;
    int n = 0;
    while((ch = getchar())!=' '&& ch !='\t'&& ch !='\n' && n < x)
    {
        *a = ch;
        a++;
        n++;
    }
    while(getchar() != '\n');
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