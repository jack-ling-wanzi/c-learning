#include<stdio.h>
char* string_in(char *s1,char *s2);

char* string_in(char *s1,char *s2)
{
    int n1,n2,a1,a2,n;
    _Bool f;
    for (n1=0;s1[n1];n1++);
    for (n2=0;s2[n2];n2++);
    if (n2>n1)
    return NULL;
    else
    {
        for(n=0;n<=n1-n2;n++)
        {
            for(f=1,a2=0,a1=n ; a2<n2 ; a2++,a1++)
            {
                if(s1[a1] != s2[a2])
                f = 0;
            }
            if (f==1) return &s1[n];
        }
        return NULL;
    }
}

int main(void)
{
    char s2[]="like you",s1[]="not like you";
    printf("%s\n",string_in(s1,s2));
    return 0;
}