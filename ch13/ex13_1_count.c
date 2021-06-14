// count.c -- 使用标准 I/O 读取文件
#include <stdio.h>
#include <stdlib.h> // 提供 exit() 的原型

int main(int argc, char const *argv[])
{
    int ch;   // 读取文件时，存储每个字符的地方
    FILE *fp; // 文件指针
    unsigned long count = 0;
    if (argc != 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    /**
     * fopen() 打开文件
     * 第一个参数是打开文件的名称，是一个包含该文件名的地址
     * 第二个参数是一个字符串，指定打开文件的模式
     * 返回文件指针，指向一个包含文件信息的数据对象
     **/
    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        printf("Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    /**
     * getc() 和 getchar() 类似，都可以获取字符
     * 不同的是 getc() 要指定使用哪个文件，并从文件中获取
     * 而 getchar() 直接从标准输入中获取字符
     * putc() 和 putchar() 同上
     **/
    while ((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout); // 指定输出为标准输出stdout后，与 putchar(ch); 相同
        count++;
    }
    // fclose() 关闭文件，成功返回0，否则返回EOF
    if (fclose(fp) != 0)
        printf("Error in closing file %s\n", argv[1]);
    printf("File %s has %lu characters\n", argv[1], count);

    return 0;
}
