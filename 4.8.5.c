#include<stdio.h>
int main(void)
{
    float f,time,n;
    
    printf("input your the download rate(Mb/s):");
    scanf("%f",&f);
    printf("input the size(MB):");
    scanf("%f",&n);
    time = n / f;
    
    printf("at %f megabits per second,a file of %f megabytes"
        "downloads in %f seconds",f,n,time);
    
    return 0;
}