#include<stdio.h>
#define level1 0
#define rate1 0.15
#define level2 300
#define rate2 0.20
#define level3 450
#define rate3 0.25
#define limit_hours 40
#define over_rate 1.5
#define salary_per_hours 10.0
int main(void)
{
    float taxed,base;
    int hours;
    while(printf("input your working hours per week:"),scanf("%d",&hours)==1)
    {
        if (hours < 0)
        continue;
        else if (hours <= limit_hours)
        base = hours *salary_per_hours;
        else 
        base = limit_hours*salary_per_hours+(hours-limit_hours)*over_rate;

        if (base<=level2)
        taxed = base*(1-rate1);
        else if(base>=level2 && base <level3)
        taxed = level2*(1-rate1)+(base - level2)*(1-rate2);
        else
        taxed = level2*(1-rate1)+(level3 - level2)*(1-rate2)+(base - level3)*(1-rate3);

        printf("your taxed salary is %f per week.\n",taxed);
    }
    return 0;
}