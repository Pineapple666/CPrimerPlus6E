// list.h 简单链表类型的头文件
#ifndef LIST_H_
#define LIST_H_

#include <stdbool.h> // C99 特性

// 指定程序的声明
#define TSIZE 45 // 存储电影名的数组大小
struct film
{
    char title[TSIZE];
    int rating;
};

// 一般类型定义
typedef struct film Item;
typedef struct node
{
    Item item;
    struct node *next;
} Node;
typedef Node *List;

// 函数原型
/**
 * @brief 初始化一个链表为空
 * 
 * @param plist 链表指针
 */
void InitalizeList(List *plist);

/**
 * @brief 判断链表是否为空
 * 
 * @param plist 指向一个已初始化的链表
 * @return true 链表为空
 * @return false 链表不为空
 */
bool ListIsEmpty(const List *plist);

/**
 * @brief 判断链表是否已满
 * 
 * @param plist 指向一个已初始化的链表
 * @return true 链表已满
 * @return false 链表未满
 */
bool ListIsFull(const List *plist);

/**
 * @brief 确定链表中的项数
 * 
 * @param plist 指向一个已初始化的链表
 * @return unsigned int 链表中的项数
 */
unsigned int ListItemCount(const List *plist);

/**
 * @brief 在链表的末尾添加项
 * 
 * @param item 待添加至链表的项
 * @param plist 指向一个已初始化的链表
 * @return true 添加成功
 * @return false 添加失败
 */
bool AddItem(Item item, List *plist);

/**
 * @brief 把函数作用与链表的每一项
 * 
 * @param plist 指向一个已初始化的链表
 * @param pfun 指向一个能作用于链表每一项的函数
 */
void Traverse(const List *plist, void (*pfun)(Item item));

/**
 * @brief 释放已分配的内存 (如果有的话)
 * 
 * @param plist 指向一个已初始化的链表
 */
void EmptyTheList(List *plist);

#endif
