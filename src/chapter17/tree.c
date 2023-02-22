// tree.c -- 树的支持函数
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

// 局部数据类型

typedef struct pair {
	Trnode *parent;
	Trnode *child;
} Pair;

// 局部函数原型

/**
 * @brief 创建一个节点
 * 
 * @param pi 指向节点保存的内容
 * @return Trnode* 创建好的节点的指针
 */
static Trnode *MakeNode(const Item *pi);

/**
 * @brief 新项于目标项作比较，判断是否将新项放入目标项左边，即左子树中
 * 
 * @param i1 新项
 * @param i2 目标项
 * @return true 放入左子树
 * @return false 不放入左子树
 */
static bool ToLeft(const Item *i1, const Item *i2);

/**
 * @brief 新项与目标项作比较，判断是否将新项放入目标项右边，即右子树中
 * 
 * @param i1 新项
 * @param i2 目标项
 * @return true 放入右子树
 * @return false 不放入右子树
 */
static bool ToRight(const Item *i1, const Item *i2);

/**
 * @brief 添加一个新节点
 * 
 * @param new_node 指向待添加的新节点
 * @param root 指向树的根节点
 */
static void AddNode(Trnode *new_node, Trnode *root);

/**
 * @brief 按照 左-根-右 的顺序将函数作用于树的每一项
 * 
 * @param root 指向树的根节点
 * @param pfun 指向一个函数
 */
static void InOrder(const Trnode *root, void (*pfun)(Item item));

/**
 * @brief 查找某一项
 * 
 * @param pi 指向带查找的项
 * @param ptree 指向带查找的树
 * @return Pair 一个包含当前项所在节点和其父节点的结构
 */
static Pair SeekItem(const Item *pi, const Tree *ptree);

/**
 * @brief 删除指定节点
 * 
 * @param ptr 指向目标节点的指针的地址，即指针的指针
 */
static void DeleteNode(Trnode **ptr);

/**
 * @brief 删除所有节点
 * 
 * @param root 指向待删除的树的根节点
 */
static void DeleteAllNodes(Trnode *root);

// 函数定义

void InitailizeTree(Tree *ptree)
{
	ptree->root = NULL;
	ptree->size = 0;
}

bool TreeIsEmpty(const Tree *ptree)
{
	if (ptree->root == NULL)
		return true;
	return false;
}

bool TreeIsFull(const Tree *ptree)
{
	if (ptree->size == MAXITEMS)
		return true;
	return false;
}

int TreeItemCount(const Tree *ptree)
{
	return ptree->size;
}

bool AddItem(const Item *pi, Tree *ptree)
{
	Trnode *new_node;
	if (TreeIsFull(ptree)) {
		fprintf(stderr, "Tree is full\n");
		return false;
	}
	if (SeekItem(pi, ptree).child != NULL) {
		fprintf(stderr, "Attempted to add duplicate item\n");
		return false;
	}
	new_node = MakeNode(pi); // 指向新节点
	if (new_node == NULL) {
		fprintf(stderr, "Couldn't create node\n");
		return false;
	}
	// 成功创建了一个新节点
	ptree->size++;
	if (ptree->root == NULL) // 情况1：树为空
		ptree->root = new_node; // 新节点为树的根节点
	else // 情况2：树不为空
		AddNode(new_node, ptree->root); // 在树中添加新节点

	return true;
}

bool InTree(const Item *pi, Tree *ptree)
{
	return (SeekItem(pi, ptree).child == NULL) ? false : true;
}

bool DeleteItem(const Item *pi, Tree *ptree)
{
	Pair look;
	look = SeekItem(pi, ptree);
	if (look.child == NULL)
		return false;
	if (look.parent == NULL) // 删除根节点项
		DeleteNode(&ptree->root);
	else if (look.parent->left == look.child)
		DeleteNode(&look.parent->left);
	else
		DeleteNode(&look.parent->right);
	ptree->size--;

	return true;
}

void Traverse(const Tree *ptree, void (*pfun)(Item item))
{
	if (ptree != NULL)
		InOrder(ptree->root, pfun);
}

void DeleteAll(Tree *ptree)
{
	if (ptree != NULL)
		DeleteAllNodes(ptree->root);
	ptree->root = NULL;
	ptree->size = 0;
}

// 局部函数

static Trnode *MakeNode(const Item *pi)
{
	Trnode *new_node;
	new_node = (Trnode *)malloc(sizeof(Trnode));
	if (new_node != NULL) {
		new_node->item = *pi;
		new_node->left = NULL;
		new_node->right = NULL;
	}

	return new_node;
}

static bool ToLeft(const Item *i1, const Item *i2)
{
	int comp1;
	if ((comp1 = strcmp(i1->petname, i2->petname)) < 0)
		return true;
	else if (comp1 == 0 && strcmp(i1->petkind, i2->petkind) < 0)
		return true;
	else
		return false;
}

static bool ToRight(const Item *i1, const Item *i2)
{
	int comp1;
	if ((comp1 = strcmp(i1->petname, i2->petname)) > 0)
		return true;
	else if (comp1 == 0 && strcmp(i1->petkind, i2->petkind) > 0)
		return true;
	else
		return false;
}

static void AddNode(Trnode *new_node, Trnode *root)
{
	if (ToLeft(&new_node->item, &root->item)) {
		if (root->left == NULL)
			root->left = new_node; // 把节点添加到此处
		else
			AddNode(new_node, root->left); // 否则处理该子树
	} else if (ToRight(&new_node->item, &root->item)) {
		if (root->right == NULL)
			root->right = new_node;
		else
			AddNode(new_node, root->right);
	} else {
		fprintf(stderr, "location error in AddNode()\n");
		exit(EXIT_FAILURE);
	}
}

static void InOrder(const Trnode *root, void (*pfun)(Item item))
{
	if (root != NULL) {
		InOrder(root->left, pfun);
		(*pfun)(root->item);
		InOrder(root->right, pfun);
	}
}

static Pair SeekItem(const Item *pi, const Tree *ptree)
{
	Pair look;
	look.parent = NULL;
	look.child = ptree->root;
	if (look.child = NULL)
		return look;
	while (look.child != NULL) {
		if (ToLeft(pi, &(look.child->item))) {
			look.parent = look.child;
			look.child = look.child->left;
		} else if (ToRight(pi, &(look.child->item))) {
			look.parent = look.child->right;
			look.child = look.child->right;
		} else // 如果前两种情况都不确定，则必定是相等的情况
			break; // look.child 目标项的节点
	}

	return look;
}

static void DeleteNode(Trnode **ptr)
{
	Trnode *temp;
	if ((*ptr)->left == NULL) {
		temp = *ptr;
		*ptr = (*ptr)->right;
		free(temp);
	} else if ((*ptr)->right == NULL) {
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	} else // 被删除的节点有两个子节点
	{
		// 找到重新连接右子树的位置
		for (temp = (*ptr)->left; temp->right != NULL;
		     temp = temp->right)
			continue;
		temp->right = (*ptr)->right;
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
}

static void DeleteAllNodes(Trnode *root)
{
	Trnode *pright;
	if (root != NULL) {
		pright = root->right;
		DeleteAllNodes(root->left);
		free(root);
		DeleteAllNodes(pright);
	}
}
