#include<stdio.h>
#include<string.h>
int bigger(int,int);
int max1(int * ,int);
int max2(int * p,int num);
int main(void)
{
    int numbers[9] = {5,4,3,8,6,1,7,9,2};
    printf("%d\n",max1(numbers,9));
    printf("%d",max2(numbers,9));
    return 0;
}

int max1(int * p,int num)
{
    int max[num],n;
    for (n=0;n*2+1<num;n++)
    {
        max[n] = bigger(p[2*n],p[2*n+1]);
    }
    if (num % 2)
    {
        max[n + 1]=p[num -1];
    }
    if( sizeof(max)/4 >1)
    {
        if(num%2)
        max1(max,n+1);
        else
        max1(max,n);
    }
    return max[0];

}

int bigger(int a,int b)
{
    return a > b?a:b;
}

int max2(int * p,int num)
{
    int n1,n2;
    _Bool big = 1;
    for (n1 = 0;n1<num;n1++)
    {
        big = 1;
        for (n2 = 0;n2<num;n2++)
        {
            if (p[n1]<p[n2])
            {
                big = 0;
                break;
            }
        }
        if (big != 0)
        return p[n1]; 
    }
}