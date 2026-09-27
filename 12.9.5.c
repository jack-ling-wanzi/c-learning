static unsigned int i = 1;

int r(void)
{
    i = i*123 + 456;
    return (i>>16) % 256;
}
#include<stdio.h>
void pop_range(int *p,int n);
int main(void)
{
    int n,num[900];
    for(n=0;n<900;n++)
    {
        num[n] = r();
        printf("%d ",num[n]);
    }
    pop_range(num,900);
    printf("\n\n");
    for(n=0;n<900;n++)
    {
        printf("%d ",num[n]);
    }
}

void pop_range(int *p,int n)
{
    int *p1,*p2,n1,temp;
    for(n1=0;n1<n-1;n1++)
    {
        for(p1=p;p1<p+n-n1-1;p1++)
        {
            if(*p1 > *(p1+1))
            {
                temp = *p1;
                *p1 = *(p1+1);
                *(p1+1) = temp;
            }
            
        }
    }
    
}