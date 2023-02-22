/**
 * @file ex6_getsputs.c
 * @brief 使用gets()和puts()
 * @date 2022-09-21
 */
#include <stdio.h>

#define STLEN 5

int main(void)
{
    char words[STLEN];
    puts("Enter a string, please.");
    gets(words); // 典型用法
    printf("Your string twice:\n");
    printf("%s\n", words);
    puts(words);
    puts("Done.");

    return 0;
}
