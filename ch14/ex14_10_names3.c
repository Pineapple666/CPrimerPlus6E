// names1.c -- 使用指向结构的指针
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NLEN 30

struct namect {
	char *fname;
	char *lname;
	int letters;
};

void getinfo(struct namect *); // 分配内存

void makeinfo(struct namect *);

void showinfo(const struct namect *);

char *s_gets(char *st, int n);

void cleanup(struct namect *); // 释放内存

int main(void)
{
	struct namect person;
	getinfo(&person);
	makeinfo(&person);
	showinfo(&person);
	cleanup(&person);

	return 0;
}

void getinfo(struct namect *pst)
{
	char temp[NLEN];
	printf("Please enter your first name.\n");
	s_gets(temp, NLEN);
	pst->fname =
		(char *)malloc(strlen(temp) + 1); // 根据temp大小，动态分配内存
	strcpy(pst->fname, temp); // 拷贝数据

	printf("Please enter your last name.\n");
	s_gets(temp, NLEN);
	pst->lname = (char *)malloc(strlen(temp) + 1);
	strcpy(pst->lname, temp);
}

void makeinfo(struct namect *pst)
{
	pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void showinfo(const struct namect *pst)
{
	printf("%s %s, your name contains %d letters.\n", pst->fname,
	       pst->lname, pst->letters);
}

void cleanup(struct namect *pst)
{
	free(pst->fname);
	free(pst->lname);
}

char *s_gets(char *st, int n)
{
	char *ret_val;
	char *find;
	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}
