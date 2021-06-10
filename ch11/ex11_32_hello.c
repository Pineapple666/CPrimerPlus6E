#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i, times;
    // atoi()将字符转为整数
    if (argc < 2 || (times = atoi(argv[1])) < 1)
        printf("Usage: %s positive - number\n", argv[0]);
    else
        for (i = 0; i < times; i++)
            printf("Hello, good looking!\n");

    return 0;
}
