// aligned_alloc.c -- 使用 aligned_alloc() 对齐动态内存的分配
#include <stdio.h>
#include <stdlib.h> // 使用aligned_alloc()

int main(void)
{
    /**
     * 第一个参数代表指定的对齐
     * 第二个参数代表所需的字节数，应是第一个参数的倍数
     * 返回一个指针
     */
    char *p = (char *)aligned_alloc(sizeof(int), 100 * sizeof(double));
    printf("%p\n", p);
    free(p);

    return 0;
}
