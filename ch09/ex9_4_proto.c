#include <stdio.h>

int imax(int, int);

int main(void)
{
    printf("The maximun of %d and %d is %d.\n", 3, 5, imax(3, 5));
    // printf("The maximum of %d and %d is %d.\n", 3, 5, imax(3.0, 5.0));
    printf("The maximum of %d and %d is %d.\n", 3.9, 5.4, imax(3.9, 5.4));
    
    return 0;
}

int imax(int n, int m)
{
    return (n > m ? n : m);
}
