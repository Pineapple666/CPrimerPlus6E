#include <stdio.h>
#include <stdlib.h> // 为了使用exit()

int main(void)
{
	int ch;
	FILE *fp;
	char fname[50]; // 存储文件名
	printf("Enter the name of the file: ");
	scanf("%s", fname);
	printf("will open %s\n", fname);
	fp = fopen(fname, "r"); // 打开带读取的文件
	if (fp == NULL) { // 如果失败
		printf("Failed to open file. Bye\n");
		exit(EXIT_FAILURE); // 退出程序
	}
	// getc(fp)从打开的文件中获取一个字符
	while ((ch = getc(fp)) != EOF)
		putchar(ch);
	fclose(fp); // 关闭文件

	return EXIT_SUCCESS;
}
