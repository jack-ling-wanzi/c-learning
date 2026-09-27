#include<stdio.h>
#define sh_g 3.785
#define km_yl 1.609
int main(void)
{
    float f,t,n,tt;
    
    printf("input the mile:");
    scanf("%f",&f);
    printf("input the fule consumption(litre):");
    scanf("%f",&n);
    t = f / n;
    printf("fule consumption per litre: %.1f mile/galon.\n",t);
    tt = t / km_yl * sh_g;
    printf("fule consumption per litre: %.1f km/litre",tt);
    
    
    
    return 0;
}