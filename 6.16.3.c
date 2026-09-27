#include<stdio.h>
int main(void)
{
    int i;
    char a,n;
    for (n='f';n>='a';n--)
    {
        for (a='f',i=0;i<='f'-n;i++,a--){
            printf("%c",a);
        }
        printf("\n");
        
    }
        
    return 0;
}