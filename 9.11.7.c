#include<stdio.h>
#include<ctype.h>
int exam(char);
void letter(void);

int main(void)
{
    letter();
    return 0;
}

int exam(char ch)
{
    if (isalpha(ch))
    return (ch-'a'+1);
    else return -1;
}

void letter(void)
{
    char ch;
    int num;
    while((ch = getchar()) != EOF)
    {
        if ((num = exam(ch)) != -1)
        {
            printf("%c is letter.in the %d of letter table.\n",ch,num);
        }
        else
        {
            printf("%c is not a letter.\n",ch);
        }
    }
}