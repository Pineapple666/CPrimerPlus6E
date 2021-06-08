// escape.c -- 使用转义序列
// Created by pineapple on 2021/4/2.
//
#include <stdio.h>

int main(void)
{
    float salary;

    printf("\t\t\t\aEnter your desired monthly salary:");
//    printf("$________\b\b\b\b\b\b\b");
//    scanf("%f", &salary);
//    printf("\n\n\t\t\t$%.2f a month is $%.2f a year.", salary, salary * 12.0);
    printf("\rGee!\n");

    return 0;
}
