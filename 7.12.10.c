#include<stdio.h>
int main(void)
{
    _Bool f=1;
    char choice;
    int level;
    float income,rincome,rate1=0.15,rate2=0.28,tax;
    while(f)
    {
        printf("a)dansheng)rate<17850=0.15,overrate=0.28\n"
                "b)huzhu)rate<23750=0.15,overrate=0.28\n"
                "c)yihun,gonggyou)rate<29750=0.15,overrate=0.28\n"
                "d))yihun,liyi)rate<14875=0.15,overrate=0.28\n");
        f = scanf(" %c",&choice);
    switch(choice)
    {
        case 'a':level = 17850;break;
        case 'b':level = 23900;break;
        case 'c':level = 29750;break;
        case 'd':level = 14875;break;
        default:printf("choose again.");return 0;
    }
    printf("income:");
    scanf("%f",&income);
    if (income>level)
    tax=(income-level)*rate2+rate1*level;
    else tax = income *rate1;
    rincome = income - tax;
    printf("real income:%f\n",rincome);
    }
}