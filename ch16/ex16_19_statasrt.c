// statasrt.c
#include <assert.h>
#include <limits.h>
#include <stdio.h>

// _Static_assert(CHAR_BIT == 16, "16-bit char falsely assumed");
static_assert(CHAR_BIT == 16, "16-bit char falsely assumed");

int main(void)
{
	puts("char is 16 bits.");

	return 0;
}
