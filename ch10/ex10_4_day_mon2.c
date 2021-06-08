// day_mon2.c -- 让编译器计算元素的个数
#include <stdio.h>

int main(void)
{
    const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31};
    int index;
    // sizeof 运算符可以计算出运算对象的大小（字节为单位）
    // sizeof days 是整个数组的大小（字节），sizeof days[0] 是数组中一个元素的大小（字节）
    for (index = 0; index < sizeof days / sizeof days[0]; index++)
        printf("Month %2d has %2d days.\n", index + 1, days[index]);

    return 0;
}
