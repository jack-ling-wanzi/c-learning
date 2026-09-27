#include<stdio.h>
char * search(char*s,char t);
int main(void)
{
    char a[100]="asdf sda d d adj  dsfa",*p;
    p = search(a,'j');
    printf("%c",p?*p:'0');
    return 0;
}
char * search(char s[],char t)
{
    int n = 0;
    while(s[n])
    {
        if (s[n] == t)
        return &s[n];
        n++;
    }
    return NULL;
}