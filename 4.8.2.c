#include<stdio.h>
#include<string.h>
int main(void)
{
    char f[20];
    int ff;
    printf("input your first name:");
    scanf("%s",f);
    
    printf("%20s\n%-20s\n%*s",f,f,stlen(f)+3,f);
    
    return 0;
}