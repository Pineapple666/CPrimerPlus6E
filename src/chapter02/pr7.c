/**
 * @file pr7.c
 * @brief 打印几行 Smile
 * @date 2022-09-18
 */
#include <stdio.h>

void smile(void);

int main(void)
{
    smile();
    smile();
    smile();
    printf("\n");
    smile();
    smile();
    printf("\n");
    smile();
    printf("\n");

    return 0;
}

void smile(void)
{
    printf("Smile!");
}
