#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LIMIT 81

// 将字符串全转为大写
void ToUpper(char *);

// 统计字符串中标点符号的个数
int PunctCount(const char *);

int main(void)
{
    char line[LIMIT];
    char *find;
    puts("Please enter a line:");
    fgets(line, LIMIT, stdin);
    find = strchr(line, '\n'); // 查找换行符
    if (find)
        *find = '\0';
    ToUpper(line);
    puts(line);
    printf("That line has %d punctuation characters.\n", PunctCount(line));

    return 0;
}

void ToUpper(char *str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}

int PunctCount(const char *str)
{
    int ct = 0;
    while (*str)
    {
        if (ispunct(*str))
            ct++;
        str++;
    }

    return ct;
}
