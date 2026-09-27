/* addemup.c -- 几种常见的语句 */
#include <stdio.h>
int main(void)                   /* 计算前20个整数的和   */
{
     int count, sum,day=20;             /* 声明[1]             */

     count = 0;                  /* 表达式语句          */
     sum = 0;                    /* 表达式语句          */
     printf("input:");
     scanf("%d",&day);
     while (count++ < day)        /* 迭代语句            */
          sum = sum + count;
     printf("sum = %d\n", sum);  /* 表达式语句[2]         */

     return 0;                /* 跳转语句                */
}