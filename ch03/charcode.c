// char_code.c -- 显示字符的代码编号
// Created by pineapple on 2021/4/1.
//
#include <stdio.h>

int main(void)
{
	char ch;

	printf("Please enter a character.\n");
	scanf("%c", &ch);
	printf("The code for %c is %d.\n", ch, ch);

	return 0;
}