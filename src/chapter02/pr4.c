/**
 * @file pr4.c
 * @brief 自定义函数输出
 * @date 2022-09-18
 */
#include <stdio.h>

void jolly(void);
void deny(void);

int main(void)
{
    jolly();
    deny();

    return 0;
}

/**
 * @brief 打印三行文本
 * 
 */
void jolly(void)
{
    for (int i = 0; i < 3; i++) {
        printf("For he's a jolly good fellow!\n");
    }
}

/**
 * @brief 打印一行文本
 * 
 */
void deny(void)
{
    printf("Which nobody can deny!\n");
}
