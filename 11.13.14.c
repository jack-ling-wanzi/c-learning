#include<stdio.h>
#include<stdlib.h>

int main(int argc,char **argv)
{
    if(argc != 3)
    {
        printf("wrong!");
        return 0;
    }

    double di,mi=1;
    int zhi,n;
    di = atof(argv[1]);
    zhi = atoi(argv[2]);
    for(n=0;n<=zhi;n++)
    {
        mi = mi * di;
    }
    printf("%lf",mi);
}