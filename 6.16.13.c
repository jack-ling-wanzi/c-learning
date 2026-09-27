#include<stdio.h>
#include<math.h>
int main(void){
    int s[8],n;
    for (n=0;n<=7;n++)
    {
        s[n]=pow(2,n+1);
    }
    n =0;
    do
    {
        printf("%d ",s[n]);
        n++;
    }
    while(n<8);
}