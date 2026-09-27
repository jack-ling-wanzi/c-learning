#include<stdio.h>
char* mystrncpy(char *t,char *s,int n)
{
    int n1=0;
    while( n1<n && s[n1]!='\0')
    {
        t[n1] = s[n1];
        n1++;
    }
    t[n1]='\0';
    return t;
}

int main(void)
{
    int n;
    char s1[10],s2[20],*p;
    while(1)
    {
        puts("input s2:");
        fgets(s2,20,stdin);

        puts("input the number to copy:");
        if (scanf("%d", &n) != 1 || n <= 0) 
        {
            while(getchar() != '\n'); // 清理垃圾输入
            continue;
        }

        if(n>9) n=9;
        p = mystrncpy(s1,s2,n);
        printf("s1:%s\n",s1);
        while(getchar() != '\n');
    }
}