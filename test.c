// test.c -- 测试文件
#include <stdio.h>

#define SIZE 3

int main(void)
{
	int arr[SIZE];

	for (int i = 1; i <= SIZE; i++)
		arr[i] = i;

	for (int i = 1; i <= SIZE; i++)
		printf("%d ", arr[i]);

	return 0;
}
