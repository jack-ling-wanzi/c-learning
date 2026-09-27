#include<stdio.h>
void chline(char,int,int);
int main(void)
{
    int j,i;
    char ch;
    while(scanf(" %c%d%d",&ch,&i,&j))
    {
        chline(ch,i,j);
    }
    return 0;
}
void chline(char ch,int i,int j)
{
    int n,m;
    for (n = 1;n <= j;n++)
    {
        for (m = 1;m<=i;m++)
        putchar(ch);
        printf("\n");
    }
}