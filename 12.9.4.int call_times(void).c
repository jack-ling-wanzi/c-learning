int call_times(void)
{
    static int time;
    time++;
    return time;
}
#include<stdio.h>
int main(void)
{
    int n;
    for (n=0 ; n<100;n++)
    {
        printf("%d ",call_times());
    }
    return 0;
}
