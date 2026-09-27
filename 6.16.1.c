#include<stdio.h>
int main(void)
{
    char s[26],a,n;
    for (a='a',n=0;a<='z';a++,n++)
        s[n]=a;
    for (n=0;n<26;n++)
        printf("%c",s[n]);
    return 0;
}