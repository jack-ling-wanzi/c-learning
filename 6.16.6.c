#include<stdio.h>

int main(void)
{
    int top=10,botom=1,count_1,number;
    printf("input botom:");scanf("%d",&botom);
    printf("input top:");scanf("%d",&top);
    printf("    number     square       cubic\n");
    for (count_1=0;count_1<=top-botom;count_1++)
    {
        number=botom+count_1;
        printf("%10d %10d %10d",number,number*number,number*number*number);
        printf("\n");
    }
    return 0;
}