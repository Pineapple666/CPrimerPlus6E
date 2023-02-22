/**
 * @file ex7_fgets1.c
 * @brief 使用fgets()和fputs()
 * @date 2022-09-21
 */
#include <stdio.h>

#define STLEN 14

int main(void)
{
    char words[STLEN];
    puts("Enter a string please.");
    fgets(words, STLEN, stdin);
    printf("Your string twice (puts(), then fputs()):\n");
    puts(words);
    fputs(words, stdout); // 不在字符串末尾添加换行符
    puts("Enter another string, please.");
    fgets(words, STLEN, stdin);
    printf("Your string twice (puts(), then fputs()):\n");
    puts(words);
    fputs(words, stdout);
    puts("Done.");

    return 0;
}
