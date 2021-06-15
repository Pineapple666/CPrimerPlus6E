#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char temp[] = "I am pineapple.\n";
    char *desc;
    desc = (char *)malloc(strlen(temp) + 1);
    printf("%s, %p\n", desc, desc);
    free(desc);

    return 0;
}
