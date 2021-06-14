#include <stdio.h>
#include <string.h>
unsigned char *InverseStr(unsigned char t[], unsigned char s[])
{
    int i, j, len = strlen((char *)s);
    for (i = len - 1, j = 0; i >= 0; --i, ++j)
    {
        if (s[i] > 0X7F)
        { // 是汉字
            t[j++] = s[i - 1];
            t[j] = s[i];
            --i;
        }
        else
            t[j] = s[i];
    }
    t[j] = '\0';
    return t;
}
int main()
{
    unsigned char s[] = "C语言char数据类型练习";
    unsigned char t[25];
    printf("s = \"%s\"\n", s);
    printf("t = \"%s\"\n", InverseStr(t, s));
    return 0;
}