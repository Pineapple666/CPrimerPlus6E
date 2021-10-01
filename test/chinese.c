#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char c[] = "哈";
	// 13A7E
	// 10011101001111110
	// −11011 −1101101 −1111000

	for (int i = 0; i < strlen(c); i++) {
		printf("%d  ", c[i]);
	}

	printf("\n");

	return 0;
}
