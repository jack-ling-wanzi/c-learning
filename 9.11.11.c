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
    unsigned long set[n + 1],a,sum;
    set[0] = 0;
    set[1] = 1;
    set[2] = 1;
    for (a=3;a<=n;a++)
    set[a] = set[a-1] + set[a-2];
    for (a = 1,sum = 0;a<=n;a++)
    {
        printf("%lu ",set[a]);
        sum += set[a];
    }
    printf("sum:%lu\n",sum);

}