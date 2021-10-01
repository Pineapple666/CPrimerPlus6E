// print2.c -- 更多printf()的特性
#include <stdio.h>

int main(void)
{
	unsigned int un = 3000000000;
	short end = 200;
	long big = 65537;
	long long very_big = 12345678908642;

	printf("un = %u and not %d\n", un, un);
	printf("end = %hd and not %d\n", end, end);
	printf("big = %ld and not %hd\n", big, big);
	printf("very_big = %lld and not %ld\n", very_big, very_big);

	return 0;
}