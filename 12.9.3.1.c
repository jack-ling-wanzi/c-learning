
#include <stdio.h>
#include "12.9.2.h"
int main(void)
{
    int mode;
    _Bool mode_;

    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);
    while (mode >= 0)
    {
        mode_ = set_mode(mode);
        get_info(mode_);
        show_info(mode_);
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d", &mode);
    }
    printf("Done.\n");
    return 0;
}