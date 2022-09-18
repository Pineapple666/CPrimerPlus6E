/**
 * @file ex2_2_fathm_ft.c
 * @brief 把2英寸转换为英尺
 * @date 2022-09-18
 */
#include <stdio.h>

int main(void)
{
    int feet, fathoms;

    fathoms = 2;
    feet = 6 * fathoms;

    printf("There are %d feet in %d fathoms!\n", feet, fathoms);
    printf("Yes, I said %d feet!\n", 6 * fathoms);

    return 0;
}
