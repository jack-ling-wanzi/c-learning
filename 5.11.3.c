#include<stdio.h>
int main(void)
{
    int day;
    scanf("%d",&day);
    while (day>0)
    {
        printf("%d days are as %d weeks and %d days.\n",day,day/7,day%7);
        printf("input:");
        scanf("%d",&day);
    }
    printf("done");
    return 0;
}