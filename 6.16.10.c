#include<stdio.h>
int square_sum(void);
int main(void)
{
    int min,max,sum=0,min_;
    printf("Enter lower and upper integer limits:");
    square_sum();
    printf("Enter next set of limits:");
    while(square_sum()){
    printf("Enter next set of limits:");
    }
    printf("Done");
    return 0;
}

int square_sum(void)
{
    int min_,sum=0,min,max;
    for (scanf("%d %d",&min,&max),min_=min;min_<=max;min_++)
        {
            sum  += min_*min_;
        }
    if (min<max)
        {
            printf("The sums of the squares from %d to %d is %d.\n",min,max,sum);
        }
    if (min>=max){return 0;}
    if (min<max){
        return 1;
    }
}