/**
 * @file demo.c
 * @date 2023-02-22
 * @author James Wang
 * @email james_wangx@163.com
 * @brief 
 */
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#ifdef _POSIX_PATH_MAX
#define PATHNAME_MAX _POSIX_PATH_MAX
#else
#define PATHNAME_MAX 1000
#endif

int main(void) {
    char buf[PATHNAME_MAX];
    if (getcwd(buf, sizeof(buf)) == NULL) {
        fprintf(stderr, "getcwd error: %s", strerror(errno));
        exit(1);
    }
    printf("current work path: %s\n", buf);

    char *s;

    return 0;
}
