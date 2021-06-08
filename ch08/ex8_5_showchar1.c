// showchar1.c -- 有较大 I/O 问题的程序
#include <stdio.h>

void display(char cr, int lines, int width);

int main(void)
{
    char ch;         // 待打印字符
    int rows, cols; // 行数和列数
    printf("Enter a character and two integers:\n");

    while ((ch = getchar()) != '\n')
    {
        int result = scanf("%d %d", &rows, &cols);
        display(ch, rows, cols);
        // 编译器给出类型转换的警告，用强制类型转换
        // display((char)ch, rows, cols);
        printf("Enter another character and two integers;\n");
        printf("Enter a newline to quit.\n");
    }

    printf("Bye.\n");

    return 0;
}

void display(char cr, int lines, int width)
{
    int row, col;
    for (row = 1; row <= lines; row++)
    {
        for (col = 1; col <= width; col++)
            putchar(cr);
        putchar('\n');
    }
}
