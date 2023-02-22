/**
 * @file ex6_altnames.c
 * @brief 可移植整数类型名
 * @date 2022-09-20
 */
#include <stdio.h>
#include <inttypes.h> // 支持可移植类型

int main(void)
{
    int32_t me32; // me32是一个有符号32位整型变量

    me32 = 45933954;
    printf("First, assume int32_t is int: ");
    printf("me32 = %d\n", me32);
    printf("Next, let's not make any assumptions.\n");
    printf("Instead, use a \"macro\" from inttypes.h: "); // \" 转义显示双引号
    printf("me32 = %" PRId32 "\n", me32);

    return 0;
}