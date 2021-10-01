// band_count.c -- 参数错误的情况
// Created by pineapple on 2021/4/2.
//
#include <stdio.h>

int main(void)
{
	int n = 4;
	int m = 5;
	float f = 7.0f;
	float g = 8.0f;

	printf("%d\n", n, m); // 参数太多
	printf("%d %d %d\n", n); // 参数太少
	printf("%d %d\n", f, g); // 参数类型不匹配
}