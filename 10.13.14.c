#include<stdio.h>
void collect(int a,int b,double s[a][b]);
double average(int b,double s[b]);
double all_average(int a,int b,double s[a][b]);
double max1(double * p,int num);
double max2(int a,int b,double s[a][b]);

void printf_(int b,double con[b]);
void printf_2(int a,int b,double con[a][b]);

int main(void)
{
    double s[3][5],ave;
    collect(3,5,s);
    printf_2(3,5,s);
    ave = all_average(3,5,s);
    printf("all average is %f.\n"
        "max number is %f.\n",ave,max2(3,5,s));
    return 0;
}
void collect(int a,int b,double s[a][b])
{
    int n;
    printf("input %d numbers:\n",a*b);
    for(n=0;n<a*b;n++)
    {
        scanf("%lf",&s[(n-(n%b))/b][n%b]);
    }
}
double average(int b,double s[b])
{
    int sum=0,n;;
    for(n = 0;n<b;n++)
    {
        sum += s[n];
    }
    return sum/b;
}
double all_average(int a,int b,double s[a][b])
{
    int n,sum = 0;
    for (n=0;n<a;n++)
    {
        printf("average of row %d is %f.\n",n+1,average(b,s[n]));
        sum += average(b,s[n]);
    }
    return sum/a;
}
double max1(double * p,int num)
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
double max2(int a,int b,double s[a][b])
{
    int n;
    _Bool big = 1;
    double maxs[a];

    for (n = 0;n < a;n++)
    maxs[n]=max1(s[n],b);

    return max1(maxs,a);
}
void printf_(int b,double con[b])
{
    int m;
        for (m = 0;m<b;m++)
        {
            printf("%lf ",con[m]);
        }
        printf("\n");
    
}
void printf_2(int a,int b,double con[a][b])
{
    int m,n;
        for (m = 0;m<a;m++)
        {
            printf_(b,con[m]);
        }
        printf("\n");
}