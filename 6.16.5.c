#include<stdio.h>
int main(void)
{
    char give,leter;
    int count_1,count_2;
    printf("input a leter:");
    scanf("%c",&give);
    for (count_1=0;count_1<give-'a'+1;count_1++)
    {
        for(count_2=give - 'a' - count_1;count_2>0;count_2--)
        printf(" ");
        for(leter='a',count_2=0;count_2<count_1;count_2++,leter++)
        printf("%c",leter);
        printf("%c",'a'+count_1);
        for(leter='a'+count_1-1,count_2=0;count_1>1,count_2<count_1;count_2++,leter--)
        printf("%c",leter);
        printf("\n");
    }
    return 0;
}