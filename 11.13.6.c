#include<stdio.h>
int is_within(char*s,char t);
int main(void)
{
    char a[100]="asdf sda d d adj  dsfa";
    int p;
    p = is_within(a,'j');
    printf("%d",p);
    return 0;
}
int is_within(char*s,char t)
{
    int n = 0;
    while(s[n])
    {
        if (s[n] == t)
        return n;
        n++;
    }
    return 0;
}