/**
 * @file ex2_print1.c
 * @brief 演示print()的一些特性
 * @date 2022-09-19
 */
#include <stdio.h>

int main(void)
{
    int ten = 10;
    int two = 2;

    printf("Doing it right: ");
    printf("%d minus %d is %d\n", ten, 2, ten - two);
    printf("Doing it wrong: ");
    /* 遗漏两个参数，编译器报出警告：
	 * warning: more '%' conversions than data arguments
	 */
    printf("%d minus %d is %d\n", ten); // 遗漏2个参数

    return 0;
}
