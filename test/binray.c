#include <stdio.h>

int main(void)
{
	printf("%d\n", 0b1);
	printf("%c\n", 0b1 + '0');
	printf("%c\n", 0b0 + '0');
	printf("%c\n", 1 + 'a');
	printf("%d\n", 0 + 'a');

	return 0;
}
