#include<stdio.h>
#include<string.h>
int max2(double * p,int num);
int main(void)
{
    double numbers[9] = {5,4,3,8,6,1,7,9,2};
    printf("%d",max2(numbers,9));
    return 0;
}

int max2(double * p,int num)
{
    int n1,n2;
    _Bool big = 1;
    for (n1 = 0;n1<num;n1++)
    {
        big = 1;
        while (big)
        {
            for (n2 = 0;n2<num;n2++)
            {
                if (p[n1]<p[n2])
                {
                    big = 0;
                    break;
                }
            }
            if (big == 0)
            {
                break;
            }
            else return n1;
        }   
    }
}