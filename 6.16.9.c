#include<stdio.h>
void cal(void);
int main(void)
{
    cal();
    return 0;
}
void cal(void)
{
    float num1,num2;
    while(scanf("%f %f",&num1,&num2)==2)
    {
        printf("%f\n",(num1-num2)/num1*num2);
    }
}