/* guess.c -- 一个拖沓且错误的猜数字程序 */
#include <stdio.h>
int main(void)
{
     int guess = 50,small = 1,big = 100;
     char f;

     printf("Pick an integer from 1 to 100. I will try to guess ");
     printf("it.\nRespond with a y if my guess is right and with");
     printf("\nan n if it is wrong.\n");
     printf("Uh...is your number %d?\n", guess);
     while (printf("a)too big;\nb)too small;\nc)it is.\n"),(f=getchar()) != 'y')      /* 获取响应，与 y 做对比 */
          {
               while(getchar()!='\n');
               
               switch(f)
               {
                    case 'a':big = guess;printf("is it %d\n",guess=(guess + small)/2);continue;
                    case 'b':small = guess;printf("is it %d\n",guess=(guess + big)/2);continue;
                    case 'c':printf("I knew I could do it!\n");return 0;
                    default :printf("input a,b or c,please!\n");continue;
               }
          }

     return 0;
}