#include<stdio.h>
void to_base_n(int,int);
int main(void)
{
    int a,b;
    while(scanf("%d %d",&a,&b))
    {
        to_base_n(a,b);
        printf("\n");
    }
    return 0;
}

void to_base_n(int n,int sys)
{
    int n1;
    if(n >= sys)
    {
    n1 = n/sys;
    to_base_n(n1,sys);//山重水复疑无路，柳暗花明又一村。
    printf("%d ",n % sys); 
    }
    else if(n<sys)
    printf("%d ",n);
}