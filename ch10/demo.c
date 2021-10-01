#include <stdio.h>

int main(void)
{
	int zippo[4][2] = { { 2, 4 }, { 6, 8 }, { 1, 3 }, { 5, 7 } };
	printf("zippo = %p == &zippo[0] = %p\n", zippo, &zippo[0]);
	printf("zippo[0] = %p == &zippo[0][0] = %p\n", zippo[0], &zippo[0][0]);

	return 0;
}
