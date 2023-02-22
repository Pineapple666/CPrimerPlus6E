/**
* @file ex9_band_count.c
* @brief 参数错误的情况
* @date 2022-09-29
*/
#include <stdio.h>

int main(void)
{
    int n = 4;
    int m = 5;
    float f = 7.0f;
    float g = 8.0f;

    printf("%d\n", n, m);    // 参数太多
    printf("%d %d %d\n", n); // 参数太少
    printf("%d %d\n", f, g); // 参数类型不匹配
}