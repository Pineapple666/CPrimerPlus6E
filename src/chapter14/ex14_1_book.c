// book.c -- 一本书的图书目录
#include <stdio.h>
#include <string.h>
#define MAXTITL 41 // 书名的最大长度 + 1
#define MAXAUTL 31 // 作者姓名的最大长度 + 1

char *s_gets(char *st, int n);

struct book // 结构模板： 标记是 book
{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
}; // 结构模板结束，必须有分号

int main(void)
{
	struct book library; // 把 library 声明为一个 book 类型的变量
	printf("Please enter the book title.\n");
	s_gets(library.title, MAXTITL); // 访问title部分
	printf("Now enter the author.\n");
	s_gets(library.author, MAXAUTL);
	printf("Now enter the value.\n");
	scanf("%f", &library.value);
	printf("%s by %s: $%.2f\n", library.title, library.author,
	       library.value);
	printf("%s: \"%s\" ($%.2f)\n", library.author, library.title,
	       library.value);
	printf("Done.\n");

	return 0;
}

char *s_gets(char *st, int n)
{
	char *ret_val;
	char *find;
	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(st, '\n'); // 查找换行符
		if (find)
			*find = '\0'; // 找到则换为 \0
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}
