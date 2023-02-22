// append.c -- 把文件附加到另一个文件的末尾
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define SLEN 81

void append(FILE *source, FILE *dest);

char *s_gets(char *st, int n);

int main(void)
{
	FILE *fa, *fs; // fa 指向目标文件， fs 指向源文件
	int files = 0; // 附加的文件数量
	char file_app[SLEN]; // 目标文件名
	char file_src[SLEN]; // 源文件名
	int ch;
	puts("Enter name of destination of file:");
	s_gets(file_app, SLEN);
	if ((fa = fopen(file_app, "a+")) == NULL) {
		fprintf(stderr, "Can't open %s\n", file_app);
		exit(EXIT_FAILURE);
	}
	/**
    * setvbuf() 函数创建了一个供标准I/O函数替换使用的缓冲区
    * 在打开文件流且未对流进行操作之前，使用该函数
    * 第一个参数是一个FILE 指针，指向待处理的流
    * 第二个参数指向使用的存储区，如果buf的值不是NULL，则必须创建一个缓冲区，比如用数组
    *                        如果buf的值是NULL，则自动分配一个缓冲区
    * 第三个参数mode _IOFBUF: 完全缓冲，_IOLBF: 行缓冲，_IONBF: 无缓冲
    * 第四个参数size 告诉缓冲区的大小，单位是字节
    * 
    **/
	if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0) {
		fputs("Can't create output buffer\n", stderr);
		exit(EXIT_FAILURE);
	}
	puts("Enter name of list source file (empty line to quit):");
	while (s_gets(file_src, SLEN) && file_src[0] != '\0') {
		// 判断源文件名是否与目标文件名相同
		if (strcmp(file_src, file_app) == 0)
			fputs("Can't append file to itself.\n", stderr);
		else if ((fs = fopen(file_src, "r")) == NULL)
			fprintf(stderr, "Can't open %s\n", file_src);
		else {
			if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0) {
				fputs("Can't create input buffer\n", stderr);
				continue;
			}
			append(fs, fa);
			// 判断是否读取出错
			if (ferror(fs) != 0)
				fprintf(stderr, "Error in reading file %s.\n",
					file_src);
			if (ferror(fa) != 0)
				fprintf(stderr, "Error in reading file %s.\n",
					file_app);
			// 判断源文件是否正确关闭
			if (fclose(fs) != 0)
				fprintf(stderr, "Error in closing file %s.\n",
					file_src);
			files++;
			printf("File %s appened.\n", file_src);
			puts("Next file (empty line to quit):");
		}
	}
	printf("Done appening. %d files appened.\n", files);
	// 回到目标文件头
	rewind(fa);
	printf("%s contents:\n", file_app);
	while ((ch = getc(fa)) != EOF)
		putchar(ch);
	puts("\nDone displaying.");
	fclose(fa);

	return 0;
}

void append(FILE *source, FILE *dest)
{
	size_t bytes;
	static char temp[BUFSIZE]; // 只分配一次
	/**
    * fread() 函数读取指定的文件
    * 第一个参数是文件数据在内存中的地址
    * 第二个参数是待读取数据块的大小，以字节为单位
    * 第三个参数表示待读取数据块的数量
    * 第四个参数表示待读取的文件
    * 返回成功读取项的数量，正常情况下为第三个参数
    **/
	while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
		fwrite(temp, sizeof(char), bytes, dest);
}

char *s_gets(char *st, int n)
{
	char *ret_val;
	char *find;
	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(st, '\n'); // 查找换行符
		if (find) // 如果地址不是NULL
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}
