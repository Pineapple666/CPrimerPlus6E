#include <stdio.h>
#define MONTHS 12

int main(void)
{
    int days[MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int index;
    for (index = 0; index < MONTHS; index++)
        // * 叫做间接运算符，和定义指针的* 是不一样的
        printf("Month %2d has %d days.\n", index + 1, *(days + index));

    return 0;
}
