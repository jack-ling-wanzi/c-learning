#include<stdio.h>
int s(void);//函数原型与定义不一样，会发生什么？
int main(void)
{
    s();
    s();
    s();
    printf("\n");//能用单引号吗？
    s();
    s();
    printf("\n");
    s();
    return 0;

}

int s(void)//如果也用main会怎样，会覆盖吗？
{
    printf("Smile!");
    return 0;
}