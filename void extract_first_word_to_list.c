#include<stdio.h>
#include<ctype.h>


void extract_first_word_to_list(int a,char s[a][100],char first[a][100]);

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

int main(void)
{
    int n;
    char first[3][100];
    char s[3][100] = {"  hjasf ksjaflskad jfa","   asD ASDas saDA","\n"};
    extract_first_word_to_list(3,s,first);
    for(n=0;n<3;n++)
    {
        puts(first[n]);
    }   
    return 0;
}