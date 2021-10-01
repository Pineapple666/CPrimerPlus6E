// reverse.c -- 倒序显示文件的内容
#include <stdio.h>
#include <stdlib.h>
// #include <wchar.h>
#define SLEN 81

int main(int argc, char const *argv[])
{
	char file[SLEN];
	char ch1, ch2, ch3;
	FILE *fp;
	long count, last;
	puts("Enter the name of the file to be processed;");
	scanf("%80s", file);
	if ((fp = fopen(file, "rb")) == NULL) // 只读模式
	{
		fprintf(stderr, "reverse can't open %s\n", file);
		exit(EXIT_FAILURE);
	}

	// while ((ch1 = getc(fp)) != EOF)
	//     printf("%d  ", ch1);

	/**
    * fseek() 定位到文件指定位置
    * 第一个参数是FILE 指针，指向待查找的文件
    * 第二个参数是偏移量，表示从起点起开始要移动的距离
    * 第三个参数是模式，确定起始点
    * SEED_SET   0L   文件开始处
    * SEED_CUR   1L   当前位置
    * SEED_END      文件末尾
    * 成功返回0，否则非0
    **/
	fseek(fp, 0L, SEEK_END); // 定位到文件末尾
	last = ftell(fp); // 返回一个long类型的值，表示当前位置
	for (count = 1L; count <= last; count++) {
		fseek(fp, -count, SEEK_END); // 回退
		ch1 = getc(fp);
		// 判断是否为中文
		if (ch1 < 0) {
			count++;
			fseek(fp, -count, SEEK_END);
			ch2 = getc(fp);
			count++;
			fseek(fp, -count, SEEK_END);
			ch3 = getc(fp);
			putc(ch3, stdout);
			putc(ch2, stdout);
			putc(ch1, stdout);
		} else
			putc(ch1, stdout);
	}
	putchar('\n');
	if (fclose(fp) != 0)
		fprintf(stderr, "Error: Can't closing file.\n");

	return EXIT_SUCCESS;
}
