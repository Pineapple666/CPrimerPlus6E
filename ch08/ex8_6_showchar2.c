// showchar2.c -- 按指定的行列打印字符
#include <stdio.h>

void display(char cr, int lines, int width);

int main(void)
{
	int ch;
	int rows, cols;
	printf("Enter a character and two integers:\n");

	while ((ch = getchar()) != '\n') {
		// 判断是否输入两个数字，不是则退出程序
		if (scanf("%d %d", &rows, &cols) != 2)
			break;
		display(ch, rows, cols);
		// 丢弃scanf后面的所有字符
		while (getchar() != '\n')
			continue;
		printf("Enter another character and two integers:\n");
		printf("Enter a newline to quit.\n");
	}

	printf("Bye.\n");

	return 0;
}

void display(char cr, int lines, int width)
{
	int row, col;
	for (row = 1; row <= lines; row++) {
		for (col = 1; col <= width; col++)
			putchar(cr);
		putchar('\n');
	}
}
