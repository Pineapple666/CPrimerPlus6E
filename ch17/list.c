// list.c -- 支持链表操作的函数
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// 局部函数原型
static void CopyToNode(Item item, Node *pnode);

// 接口函数

void InitalizeList(List *plist)
{
    plist = NULL;
}

bool ListIsEmpty(const List *plist)
{
    if (*plist == NULL)
        return true;
    else
        return false;
}

bool ListIsFull(const List *plist)
{
    Node *pt;
    bool full;
    pt = (Node *)malloc(sizeof(Node));
    if (pt == NULL)
        full = true;
    else
        full = false;
    free(pt);

    return full;
}

unsigned int ListItemCount(const List *plist)
{
    unsigned int count = 0;
    // pnode是指向Node的指针，plist是指向List的指针
    // 而List 是指向Node的指针名，所以可以直接复制
    Node *pnode = *plist; // 设置链表的开始
    while (pnode != NULL)
    {
        ++count;
        pnode = pnode->next; // 设置下一节点
    }

    return count;
}

bool AddItem(Item item, List *plist)
{
    Node *pnew;
    Node *scan = *plist;
    pnew = (Node *)malloc(sizeof(Node));
    if (pnew == NULL)
    {
        return false; // 失败时退出函数
    }
    CopyToNode(item, pnew);
    pnew->next = NULL;
    if (scan == NULL) // 空链表，所以把pnew放在链表的开头
    {
        *plist = pnew;
    }
    else
    {
        while (scan->next != NULL)
            scan = scan->next; // 找到链表末尾
        scan->next = pnew;
    }

    return true;
}

void Traverse(const List *plist, void (*pfun)(Item item))
{
    Node *pnode = *plist; // 设置链表的开始，List其实就是表头
    while (pnode != NULL)
    {
        (*pfun)(pnode->item); // 将函数应用于链表中的每一项
        pnode = pnode->next;  // 前进到下一项
    }
}

void EmptyTheList(List *plist)
{
    Node *psave;
    while (*plist != NULL)
    {
        psave = (*plist)->next; // 保存下一节点的地址
        free(*plist);
        *plist = psave;
    }
}

static void CopyToNode(Item item, Node *pnode)
{
    pnode->item = item; // 拷贝结构
}