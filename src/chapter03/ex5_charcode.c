/**
 * @file ex5_charcode.c
 * @brief 显示字符的代码编号
 * @date 2022-09-19
 */
#include <stdio.h>

int main(void)
{
    char ch;

    printf("Please enter a character.\n");
    scanf("%c", &ch);
    printf("The code for %c is %d.\n", ch, ch);

    return 0;
}
