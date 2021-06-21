// tree.h -- 二叉查找树
// 树中不允许有重复的项
#if !defined(_TREE_H_)
#define _TREE_H_

#include <stdbool.h>

// 根据实际情况定义 Item
#define SLEN 20
typedef struct item
{
    char petname[SLEN];
    char petkind[SLEN];
} Item;

#define MAXITEMS 10
typedef struct trnode
{
    Item item;
    struct trnode *left;  // 指向左分支的指针
    struct trnode *right; // 指向右分支的指针
} Trnode;

typedef struct tree
{
    Trnode *root; // 指向根节点的指针
    int size;     // 树的项数
} Tree;

// 函数原型

/**
 * @brief 把树初始化为空
 * 
 * @param ptree 指向一个树
 */
void InitailizeTree(Tree *ptree);

/**
 * @brief 确定树是否为空
 * 
 * @param ptree 指向一个树
 * @return true 树为空
 * @return false 树不为空
 */
bool TreeIsEmpty(const Tree *ptree);

/**
 * @brief 确定树是否已满
 * 
 * @param ptree 指向一个树
 * @return true 树已满
 * @return false 树未满
 */
bool TreeIsFull(const Tree *ptree);

/**
 * @brief 确定树的项数
 * 
 * @param ptree 指向一个树
 * @return int 树的项数
 */
int TreeItemCount(const Tree *ptree);

/**
 * @brief 在数中添加一项
 * 
 * @param pi 指向待添加的项
 * @param ptree 指向一个树
 * @return true 添加成功
 * @return false 添加失败
 */
bool AddItem(const Item *pi, Tree *ptree);

/**
 * @brief 在树中查找一项
 * 
 * @param pi 指向待查找的项
 * @param ptree 指向一个树
 * @return true 查找成功
 * @return false 查找失败
 */
bool InTree(const Item *pi, Tree *ptree);

/**
 * @brief 从树中删除一项
 * 
 * @param pi 指向待删除的项
 * @param ptree 指向一个树
 * @return true 删除成功
 * @return false 删除失败
 */
bool DeleteItem(const Item *pi, Tree *ptree);

/**
 * @brief 把函数应用于树中的每一项
 * 
 * @param ptree 指向一个树
 * @param fun 指向一个函数
 */
void Traverse(const Tree *ptree, void (*fun)(Item item));

/**
 * @brief 删除树中的所有内容
 * 
 * @param ptree 指向一个已初始化的树
 */
void DeleteAll(Tree *ptree);

#endif // _TREE_H_
