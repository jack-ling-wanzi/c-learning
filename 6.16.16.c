#include<stdio.h>
int main(void)
{
    float da=100.0,de=100.0;
    int n=0;
    while (da>=de)
    {
        da += 100*0.1;
        de += de*0.05;
        n++;
    }
    printf("year:%d,da:%f,de:%f.",n,da,de);
    return 0;
}