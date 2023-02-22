// align.c -- 使用 _Alignof 和 _Alignas (C11)
#include <stdio.h>
#include <stdalign.h> // 与C++ 关键字匹配

int main(void)
{
	double dx;
	char ca;
	char cx;
	double dz;
	char cb;
	char alignas(double) cz;
	printf("char alignment: %zd\n", alignof(char));
	printf("double alignment: %zd\n", alignof(double));
	printf("&dx: %p\n", &dx);
	printf("&ca: %p\n", &ca);
	printf("&cx: %p\n", &cx);
	printf("&dz: %p\n", &dz);
	printf("&cb: %p\n", &cb);
	printf("&cz: %p\n", &cz);

	return 0;
}
