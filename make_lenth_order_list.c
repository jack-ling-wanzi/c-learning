#include<string.h>
#include<stdio.h>

void make_lenth_order_list(int *sq,int a,char s[a][100]);
void new_order_printf(int *order,int a,char ch[a][100]);

void make_orderlist(int *sq,int a,char s[a][100])
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
void new_order_printf(int *order,int a,char ch[a][100])
{
    int n,n1;
    for(n=0;n<a;n++)
    {
        for(n1=0;n1<a;n1++)
        if(order[n1] == n )
        printf("%s\n",ch[n1]);
    }
}

void make_lenth_order_list(int *sq,int a,char s[a][100])
{
    int n,n1,number;
    int len[a];
    for(n=0;n<a;n++)
    {
        len[n] = strlen(s[n]);
    }
    for(n=0;n<a;n++)
    {
        for(number=0,n1=0;n1<a;n1++)
        {
            if(len[n] > len[n1])
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
    char s[3][100]={"zz love you","never apart","long time no see"};
    int number[3];
    make_lenth_order_list(number,3,s);
    for(n = 0;n<3;n++)
    {
        printf("%d ",number[n]);
    }
    printf("\n");
    new_order_printf(number,3,s);
    return 0;
}