#include<stdio.h>
unsigned long Fibonacci(unsigned n);
int main(void)
{
    unsigned long max;
    while(scanf("%lu",&max))
    Fibonacci(max);
    return 0;
}

unsigned long Fibonacci(unsigned n)
{
    unsigned long set[n + 4],a1,a2,a3,count,a,sum;
    set[0] = 0;
    set[1] = 1;
    set[2] = 1;
    set[n+3] = 0;
    set[n+2] = 0;
    set[n+1] = 0;
    for(a1=1,a2=1,a3 = 2,count = 3;count <= n;count += 3)
    {
        a3 = a1 + a2;//count + 0
        a1 = a2 + a3;//count + 1
        a2 = a3 + a1;//coumt + 2
        set[count + 0] = a3;
        set[count + 1] = a1;
        set[count + 2] = a2;
    }
    for (a = 1,sum = 0;a<=n;a++)
    {
        printf("%lu ",set[a]);
        sum += set[a];
    }
    printf("sum:%lu\n",sum);
}