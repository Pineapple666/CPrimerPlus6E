// queue.h -- Queue的接口
#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdbool.h>

// 这里插入Item类型的定义，例如
// typedef int Item; // 用于 use_q.c
// 或者 typedef struct item {int gumption; int charisma;} Item;

typedef struct item
{
    long arrive;     // 一位顾客加入队列的时间
    int processtime; // 该顾客咨询时花费的时间
} Item;

#define MAXQUEUE 10

typedef struct node
{
    Item item;
    struct node *next;
} Node;

typedef struct queue
{
    Node *front; // 指向队列首项的指针
    Node *rear;  // 指向队列尾项的指针
    int items;   // 队列中的项数
} Queue;

/**
 * @brief 初始化队列为空
 * 
 * @param pq 指向队列的指针
 */
void InitializeQueue(Queue *pq);

/**
 * @brief 检查队列是否已满
 * 
 * @param pq 指向已初始化的队列
 * @return true 队列已满
 * @return false 队列未满
 */
bool QueueIsFull(const Queue *pq);

/**
 * @brief 检查队列是否为空
 * 
 * @param pq 指向已初始化的队列
 * @return true 队列为空
 * @return false 队列不为空
 */
bool QueueIsEmpty(const Queue *pq);

/**
 * @brief 确定队列中的项数
 * 
 * @param pq 指向已初始化的队列
 * @return int 队列的项数
 */
int QueueItemCount(const Queue *pq);

/**
 * @brief 在队列末尾添加项
 * 
 * @param item 待添加的项
 * @param pq 指向已初始化的队列
 * @return true 添加成功
 * @return false 添加失败
 */
bool EnQueue(Item item, Queue *pq);

/**
 * @brief 在队列的开头删除项
 * 
 * @param pitem 队列中待删除的项
 * @param pq 指向已初始化的队列
 * @return true 删除成功
 * @return false 删除失败
 */
bool DeQueue(Item *pitem, Queue *pq);

/**
 * @brief 清空队列
 * 
 * @param pq 指向已初始化的队列
 */
void EmptyTheQueue(Queue *pq);

#endif