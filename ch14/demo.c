#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    const char *colors[] = {"red", "orange", "yellow", "green", "blue", "violet"};
    char *temp[] = {"a", "b", "c", "d", "e", "f"};
    printf("%s, %p, %p\n", colors[1], colors[1], &colors[1]);
    printf("%s, %p\n", temp[1], &temp[1]);

    return 0;
}
