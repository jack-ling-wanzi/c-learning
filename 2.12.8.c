#include<stdio.h>
void one_three(void);
void two(void);
void main(void)
{
    printf("Stsrting now:");
    one_three();
    printf("\nDone!");
}

void one_three(void){
    printf("\none");
    two();
    printf("\nthree!");
}

void two(void){
    printf("\ntwo");
}