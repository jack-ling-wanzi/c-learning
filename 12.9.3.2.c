#include<stdio.h>
int km,miles;
double liters,gallons;
//_Bool mode_;
_Bool set_mode(int mode)
{
    if (mode == 0)
    {
//        mode_ = 0;
        return 0;
    }
    else if(mode == 1)
    {
        //mode_ = 1;
        return 0;
    }
    else
    {
        printf("Invalid mode specified. Mode 1(US) used.\n");
        //mode_ = 1;
        return 1;
    }
}
void get_info(_Bool mode_)
{
    if(mode_ == 0)
    {
        printf("Enter distance traveled in kilometers: ");
        scanf("%d",&km);
        printf("Enter fuel consumed in liters: ");
        scanf("%lf",&liters);
    }
    else
    {
        printf("Enter distance traveled in miles ");
        scanf("%d",&miles);
        printf("Enter fuel consumed in gallons ");
        scanf("%lf",&gallons);
    }
}
void show_info(_Bool mode_)
{
    if(mode_ == 0)
    printf("Fuel consumption is %.2lf liters per 100 km.\n",liters/km*100);
    else
    printf("Fuel consumption is %.2lf liters per 100 km.\n",miles/gallons);
}