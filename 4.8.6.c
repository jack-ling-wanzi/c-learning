#include<stdio.h>
#include<string.h>
int main(void)
{
    
    char f[20],l[20];
    int ff,ll;
    printf("input your first name:");
    scanf("%s",f);
    printf("input your name:");
    scanf("%s",l);
    ff=strlen(f);
    ll=strlen(l);
    printf("%s %s",f,l);
    printf("\n%*d %*d",ff,ff,ll,ll);
    printf("\n%-*d %-*d",ff,ff,ll,ll);
    
    return 0;
}