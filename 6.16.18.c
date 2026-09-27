#include<stdio.h>
int main(void)
{
    int f=5,w=0;
    while (f<=150)
    {
        f -= w+1;
        f = f*2;
        w++;
        printf("week:%d,now friends:%d\n",w,f);
    }
}