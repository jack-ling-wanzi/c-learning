#include<stdio.h>
float get_first(void);
float get_last(void);
float d_get_last(void);
int main(void)
{
    char f;
    float first,last;
    do
    {
    printf("Enter the operation of your choice:\n\
a. add           s. subtract\n\
m. multiply      d. divide\n\
q. quit\n");
    f = getchar();
    switch(f)
    {
        case 'a':
        first=get_first();
        last = get_last();
        printf("%f + %f = %f\n",first,last,first+last);break;
        case 'd':
        first=get_first();
        last = d_get_last();
        printf("%f / %f = %f\n",first,last,first/last);break;
        case 'm':
        first=get_first();
        last = get_last();
        printf("%f * %f = %f\n",first,last,first*last);break;
        case 's':
        first=get_first();
        last = get_last();
        printf("%f - %f = %f\n",first,last,first-last);break;
        case 'q':return 0;
        default:while(getchar()!='\n');continue;
    }
    while(getchar()!='\n');
    }while(1);
}

float get_first(void)
{
    
    float num;
    printf("Enter first number:");
    while(!scanf("%f",&num))
    {
        printf("Please enter a number, such as 2.5, -1.78E8, or 3:");
        while(getchar()!='\n');
    }
    return num;
}

float get_last(void)
{
    
    float num;
    printf("Enter second number:");
    while(!scanf("%f",&num))
    {
        printf("Please enter a number, such as 2.5, -1.78E8, or 3:");
        while(getchar()!='\n');
    }
    return num;
}

float d_get_last(void)
{
    
    float num;
    _Bool f;
    printf("Enter second number:");
    while(1)
    {

    if(f = !scanf("%f",&num))
    {
        printf("Please enter a number, such as 2.5, -1.78E8, or 3:");
        while(getchar()!='\n');
    }

    else if (num == 0)
        {
            printf("Enter a number other than 0:");
            continue;
        }
    else return num;
    }
}