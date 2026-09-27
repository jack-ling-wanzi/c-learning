#include <stdio.h>
#define TEN 10
int main(void)
{
    char n = 96;

    while (n++ < 97+6)
        printf("%5c", n);
    printf("\n");
    return 0;
}