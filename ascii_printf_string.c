#include<stdio.h>

void makelist(int *sq,int a,char s[a][100]);
void order_printf(int *order,int a,char ch[a][100]);

void makelist(int *sq,int a,char s[a][100])
{
    int n,n1,number;
    char first[a];
    for(n=0;n<a;n++)
    {
        first[n] = s[n][0];
    }
    for(n=0;n<a;n++)
    {
        for(number=0,n1=0;n1<a;n1++)
        {
            if(first[n] > first[n1])
            {
                number++;
            }
        }
        sq[n] = number;
    }
}

int main(void)
{
    int n;
    char s[3][100]={"i love you","never apart","long time no see"};
    int number[3];
    makelist(number,3,s);
    for(n = 0;n<3;n++)
    {
        printf("%d ",number[n]);
    }
    order_printf(number,3,s);
    return 0;
}

void order_printf(int *order,int a,char ch[a][100])
{
    int n,n1;
    for(n=0;n<a;n++)
    {
        for(n1=0;order[n1] != n;n1++)
        ;
        printf("%s\n",ch[n1]);
    }
}