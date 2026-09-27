#include <stdio.h>
double power(double n, int p);    // ANSI函数原型
int main(void)
{
    _Bool f = 1;
    double n;
    int p;
    while(f)
    {
    f = scanf("%lf %d",&n,&p);
    printf("%lf's %d power is %lf\n",n,p,power(n,p));
    while(getchar() != '\n');
    }
    return 0;
}

double power(double n, int p)    // 函数定义
{
    double pow = 1;
    int i;
    if(p >= 1)
    {
        if (p >= 1)
        {
            pow = power(n,p-1) * n;
        }
    return pow;
    }                // 返回pow的值

    else if(p == 0)
    {
        if (n == 0)
        {
            printf("power(0,0) is not define.return 0.\n");
            return 0;
        }
        else
        {
            return 1;
        }
    }

    else 
    {
        if (p <= -1)
        {
            pow = power(n,p+1) * (1/n);
        }
        return pow;
    }
}