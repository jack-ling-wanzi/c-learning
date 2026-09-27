#include<stdio.h>
int main(void)
{
    int age;
    int s;
    printf("input your age:");
    scanf("%d",&age);
    s = age * 3.156e7;
    printf("your age is as %d seconds.",s);
    return 0;
}