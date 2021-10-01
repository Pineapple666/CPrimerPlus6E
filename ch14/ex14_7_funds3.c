// funds3.c -- 传递结构
#include <stdio.h>
#define FUNDLEN 50

struct funds {
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};

double sum(struct funds); // 参数是一个结构

int main(void)
{
	struct funds stan = { "Garlic-Melon Bank", 4032.27,
			      "Lucky's Savings and Loan", 8543.94 };
	printf("Stan has a total of %.2f.\n", sum(stan));

	return 0;
}

/**
* moolah 是 stan 的一个副本，不会改变stan
**/
double sum(struct funds moolah)
{
	return (moolah.bankfund + moolah.savefund);
}
