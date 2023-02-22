// reverse.c -- 倒序显示文件的内容
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CNTL_Z '\032' // DOS 文本文件中的文件结尾标记
#define FILE_LEN 201

int main(void) {
    char file[FILE_LEN]; // 文件名
    char file_path[FILE_LEN] = "/Users/james/Codes/c-project/c-primer-plus-6e/resource/";
    char ch;
    FILE *fp;
    long last;

    puts("Enter the name of the file to be processed: ");
    scanf("%80s", file); // 输入文件名
    strcat(file_path, file);

    if ((fp = fopen(file_path, "r")) == NULL) {
        printf("reverse can't open %s\n", file);
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0L, SEEK_END);
    last = ftell(fp);

    for (long count = 1L; count <= last; count++) {
        fseek(fp, -count, SEEK_END);
        ch = getc(fp);
        if (ch != CNTL_Z && ch != '\r')
            putchar(ch);
    }

    putchar('\n');
    fclose(fp);

    return 0;
}
