#include<ctype.h>
#include<stdio.h>

void cal_the_num_of_word_leter_punct_number(void);

void cal_the_num_of_word_leter_punct_number(void)
{
    _Bool prech=0;
    char ch;
    int word=0,upper=0,lower=0,punct=0,number=0;

    while( (ch = getchar()) != EOF)
    {
        if(isalpha(ch))
        {
            if(prech == 0)
            word++;
            prech = 1;

            if(isupper(ch))
            upper++;
            else lower++;
        }
        else prech = 0;

        if(ispunct(ch))
        punct++;

        if(isdigit(ch))
        number++;
    }
    getchar();
    printf("word = %d,upper_leter = %d,lower_leter = %d,punct = %d,number = %d.\n",word,upper,lower,punct,number);

}

int main(void)
{
    cal_the_num_of_word_leter_punct_number();

    return 0;
}