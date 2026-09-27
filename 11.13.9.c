#include<stdio.h>
void invert(char * p);
void invert(char * p)
{
    int n1,n2,num;
    double temp;
    for(num=0;p[num];num++);
    for(n1=num-1,n2=0;n1>=n2;n1--,n2++)
    {
        temp=p[n1];
        p[n1]=p[n2];
        p[n2]=temp;
    }
}

int main(void)
{
    char le[]="nobo dy";
    invert(le);
    printf("%s",le);
}