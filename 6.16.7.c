#include<stdio.h>
#include<string.h>
int main(void)
{
    char leter[100];
    int last;
    printf("input a leter:");
    scanf("%s",leter);
    last=strlen(leter);
    for (;last>=0;last--)
    printf("%c",leter[last]);
    return 0;
}