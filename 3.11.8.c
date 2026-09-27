#include<stdio.h>
int main(void)
{
    float pt,b,as,ts,cs;
    printf("input b:");
    scanf("%f",&b);
    pt = b*2;
    as = b/8;
    ts = as * 2;
    cs = ts / 3;
    printf("%fb=%fpt=%fas=%fts=%fcs",b,pt,as,ts,cs);
    return 0;
}