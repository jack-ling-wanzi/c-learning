#include<stdio.h>
#include<ctype.h>

void remove_space(char *s);

/*
void remove_space(char *s)
{
    int n,n1;
    for(n=0;s[n];n++);
    char t[n];
    for(n1=0,n=0;s[n];n++)
    {
        if(!isspace(s[n]))
        {
            t[n1] = s[n];
            n1++;
        }
    }
    for(n=0;t[n];n++)
    {
        s[n]=t[n];
    }
}
*/

int main(void)
{
    char s[100],*f;
    do
    {
        if(*fgets(s,100,stdin) == '\n')break;
        remove_space(s);
        printf("%s\n",s);
    }while(1);

    return 0;

}

void remove_space(char *s)
{
    int n,n1;
    int read,write;
    for(read=0,write=0;s[read];read++)
    {
        if(!isspace(s[read]))
        {
            s[write] = s[read];
            write++;
        }
    }
    s[write]='\0';
}