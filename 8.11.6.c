#include<stdio.h>
#include<ctype.h>
char get_first(void);
int main(void)
{
     char first;

     first = get_first();
     printf("first letter:%c",first);
     return 0;
}

char get_first(void)
{
     int ch;
     while (!isalpha(ch = getchar()))
          continue;

     return ch;
}