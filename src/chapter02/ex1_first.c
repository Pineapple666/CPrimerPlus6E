/**
 * @file ex2_1_first.c
 * @brief 第一个 C 程序
 * @date 2022-09-18
 */
#include <stdio.h> // #include是预处理指令，用来包含另一个文件

int main(void) // main() 函数总是第一个被调用的函数
{
    int num; // 定义一个名为 num 的变量
    num = 1; // 为 num 赋一个值

    printf("I am a simple "); // 使用 printf() 函数
    printf("computer.\n");
    printf("My favorite number is %d because it is first.\n", num);

    return 0;
}
