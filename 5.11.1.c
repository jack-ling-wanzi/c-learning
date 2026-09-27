#include<stdio.h>
int main(void)
{
    const int sixty = 60;
    int min;
    printf("transform minutes into hours and minutes.\n"
            "input <=0 to quit.\n");
    printf("input minutess:");

    scanf("%d",&min);
    while (min > 0)
    {
        printf("%d minutes are as %d hours and %d minutes.\n",min,min/sixty,min%sixty);
        printf("input the next number.");
        scanf("%d",&min);
    }
    printf("done.");
    return 0;
}