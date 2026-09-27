#include<stdio.h>
#include<ctype.h>
#include<string.h>

void make_orderlist(int *sq,int a,char s[a][100]);
void order_printf(int *order,int a,char ch[a][100]);
void make_lenth_order_list(int *sq,int a,char s[a][100]);
void new_order_printf(int *order,int a,char ch[a][100]);
void extract_first_word_to_list(int a,char s[a][100],char first[a][100]);
char get_option(void);

int main(void)
{
    int v,count;
    char *p,ls[100],f;
    char s[10][100],first_word[10][100];
    int sequence[10],n,n1;

    puts("input a string:");
    for(count=0,n1=0;n1<10;n1++)
    {
        v = !fgets(s[n1],100,stdin);
        if(v)
        {
            break;
        }
        s[n1][strcspn(s[n1], "\n")] = '\0';
        count++;
    }

    while(1)
    {
        printf("select a way:\na)print.\nb)print under the order of ASCII.\nc)print by lenth\nd)print by the lenth of the first word.\ne)quit.\n");
        f = get_option();
        switch(f)
        {
            case 'a':
            for(n1=0;n1<count;n1++)
            {
                puts(s[n1]);
            }
            break;
            case 'b':
            make_orderlist(sequence,count,s);
            new_order_printf(sequence,count,s);
            break;
            case 'c':
            make_lenth_order_list(sequence,count,s);
            new_order_printf(sequence,count,s);
            break;
            case 'd':
            extract_first_word_to_list(count,s,first_word);
            make_lenth_order_list(sequence,count,first_word);
            new_order_printf(sequence,count,s);
            break;
            case 'e':
            return 0;
            default:
            printf("please input a,b,c,d,e.choose again.\n");
            continue;

        }

    }
    
    
}


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

void extract_first_word_to_list(int a,char s[a][100],char first[a][100])
{
    int n1,n2,n3,n4;
    char *firstp,*lastp;
    for(n1=0;n1<a;n1++)
    {
        for(n2=0;n2<100;n2++)
        {
            if (s[n1][n2] != '\0')
            {
                if(isalpha(s[n1][n2]))
                {
                    firstp = &s[n1][n2];
                    break;
                }
            }
            else firstp = 0;
        }

        if (firstp)
        {
            for(n3=n2;n3<100;n3++)
            {
                if (s[n1][n3] != '\0')
                {
                    if(!isalpha(s[n1][n3]))
                    {
                        lastp = &s[n1][n3];
                        break;
                    }
                }
                else lastp = &s[n1][n3];
            }
        }

        if(firstp)
        {
            for(n4=0;firstp<lastp;firstp++,n4++)
            {
                first[n1][n4] = *firstp;
            }
            first[n1][n4] = '\0';
        }
        else first[n1][0]='\0';
    }
}

char get_option(void)
{
    char option;
    option = getchar();
    while(getchar() != '\n')
    ;
    return option;
}