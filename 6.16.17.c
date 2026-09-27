#include<stdio.h>
int main(void)
{
    double all = 1.e6;
    int y=0;
    while (all>0)
    {
        all += all*0.08;
        all -= 1.e5;
        y++;
        printf("year:%d,left:%lf\n",y,all);
    }
    printf("year:%d",y-1);
    return 0;
}