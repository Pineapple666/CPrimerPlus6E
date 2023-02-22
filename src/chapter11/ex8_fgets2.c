/**
 * @file ex8_fgets2.c
 * @brief 使用fgets()和fputs()
 * @date 2022-09-21
 */
#include <stdio.h>

#define STLEN 10

int main(void)
{
    char words[STLEN];
    puts("Enter string (empty line to quit):");
    while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n')
        fputs(words, stdout);
    puts("Done.");

    return 0;
}
