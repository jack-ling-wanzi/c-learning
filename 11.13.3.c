#include<stdio.h>
#include<string.h>
#include<ctype.h>
void get_first_word(char target[],int);
int main(void)
{
    char a[21],*p;
    while(1){
    get_first_word(a,21);
    puts(a);
    }
    return 0;

}
void get_first_word(char target[],int n)
{
    int first,n1=0;
    while(!isalpha(first = getchar()));
    *target = first;
    fgets(target+1,n-1,stdin);
    while(n1<n&&target[n1]!='\n'&&target[n1]!='\0')
    n1++;
    if (target[n1] == '\0')
    while(getchar()!='\n');
    else if(target[n1]=='\n')
    target[n1] = '\0';
    n1=0;
    while(n1<n&&isalpha(target[n1]))
    n1++;
    target[n1-1]='\0';
}