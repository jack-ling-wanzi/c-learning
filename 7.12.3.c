#include<stdio.h>
int main(void)
{
    int n,ou=0,ji=0;float ou_sum=0.,ji_sum=0.;
    printf("input an int:");
    scanf("%d",&n);
    while (n!=0)
    {
        n%2==0?(ou++,ou_sum+=n):(ji++,ji_sum+=n);
        scanf("%d",&n);
    }
    printf("ji_num:%d,ji_average:%f,ou_num:%d,ou_average:%f.",ji,ji_sum/ji,ou,ou_sum/ou);
    return 0;
}