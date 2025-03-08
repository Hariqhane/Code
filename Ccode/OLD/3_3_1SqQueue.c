#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define Elem int
#define Maxsize 10
// #define int Elemtype
// #include <string.h>
//! SqQueue 顺序表实现的队列
typedef struct
{
    Elem data[Maxsize];
    int front, rear; // 定义队头和队尾指针, 和SqStack一样, 是int存储的索引
} SqQueue;
//! 初始化
void InitQueue(SqQueue *Q)
{
    Q->front = Q->rear = 0; // 队列为空时, 队头指针和尾指针都指向0;
}
//! 判断是否为空;
bool QueueEmpty(SqQueue Q)
{
    if (Q.rear == Q.front)
        return true;
    else
        return false;
}
//! 判断是否为满
bool QueueFull(SqQueue Q)
{

    // !方法1: 牺牲一个空间
    return (Q.rear + 1) % Maxsize == Q.front;
    //! 方法2: 在def时加入队列长度信息.
    // *那么满时, size == Maxsize ;空时, size == 0;
    //! 方法3: def 加入tag 信息, 标记最近一次进行的是插入还是删除.
    //* 原理是只有插入后才会队满, 删除后才会队空. 那么进行这两个操作时, switch tag的值为0or 1, 然后判断满/空条件为 front == rear&& tag == 1 /0 即可.
}
//! 入队
bool EnQueue(SqQueue *Q, Elem x)
{
    if (QueueFull(*Q))
        return false;
    Q->data[Q->rear] = x;
    //! 队尾指针指向 将插入的位置, 然后移动到下一个将要插入的位置
    Q->rear = (Q->rear + 1) % Maxsize; // 模运算将无限的整数域映射到有限的整数集合上;
    // 存储空间在逻辑上变成了环装;
    return true;
}
//! 获得队头元素的值;
bool GetHead(SqQueue *Q, Elem *e)
{
    if (QueueEmpty(*Q))
        return false;
    *e = Q->data[Q->front];
    return true;
}
//!  出队
bool DeQueue(SqQueue *Q, Elem *e)
{
    if (!GetHead(Q, e))
        return false;
    Q->front = (Q->front + 1) % Maxsize; // 向后移动头部指针
    return true;
}

//
int main()
{
    SqQueue Q;
    InitQueue(&Q);
    if (EnQueue(&Q, 20))
        printf("入队成功\n");
    int head;
    if (DeQueue(&Q, &head))
        printf("出队的元素是: %d\n", head);
    return 0;
}