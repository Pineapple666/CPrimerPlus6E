/**
 * @file pr3.c
 * @brief 将年龄转换为天数
 * @date 2022-09-18
 */
#include <stdio.h>

int main(void)
{
    int age;

    printf("Input your age: ");
    scanf("%d", &age);
    printf("You have live %d days in the world!\n", age * 365);

    return 0;
}
