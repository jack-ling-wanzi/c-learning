#include<stdio.h>
void jisuan(double n);
int main()
{
    int a,b;
    printf("This program computes moduli.\n"
    "nter an integer to serve as the second operand:");
    scanf("%d",&a);
    printf("Now enter the first operand:");
    scanf("%d",&b);
    while (b>0){
        printf("%d %% %d is %d.\n",b,a,b%a);
        printf("Now enter the first operand:\n");
        scanf("%d",&b);
    }
    printf("Done");
    return 0;

}