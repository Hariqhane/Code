#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define Elem int
// #include <string.h>
//队列_节点
typedef struct LinkNode
{
    Elem data;
    struct LinkNode *next;
} LinkNode;
//需要单独定义两个指针的结构体, 因为不需要每个节点都储存队头和队尾指针的信息
typedef struct
{
    LinkNode *front, *rear;
} LinkQueue;


//初始化(带头结点)
void InitQueue(LinkQueue *Q)
{
    Q->front = Q->rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q->front->next = NULL;
}

//判空1
bool EmptyQueue(LinkQueue Q)
{
    return Q.front == Q.rear;
}
//初始化(不带头结点)
void INitQueue2(LinkQueue *Q)
{
    Q->front = Q->rear = NULL;
}
//判空2
bool EmptyQueue2(LinkQueue Q)
{
    return Q.front == NULL;
}

//入队(带头结点)
void EnQueue(LinkQueue *Q, Elem x)
{
    // 入队, 要插入到rear的next, 然后将新节点作为新的rear;
    //front 不需要动, 一直指着头结点
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q->rear->next = s;
    Q->rear = s;
}

//入队(不带头结点)
//不带头结点时, 入队时也要判空. 因为第一个元素, 是头元素也是尾元素
void EnQueue2(LinkQueue *Q, Elem x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    //不带头结点的话, 入第一个结点时, 要让fornt指向第一个节点.
    if(Q->front == NULL)
    {
        Q->front = s;
        Q->rear = s;
    }
    else
    {
        Q->rear->next = s;
        Q->rear = s;
    }
}
//出队(带头结点)
bool DeQeue(LinkQueue *Q, Elem *e)
{
    //判空
    if(Q->front == NULL)
        return false;
    LinkNode *p = Q->front->next;//!这里Q->front 是头结点, p就是要出队的结点
    *e = p->data;
    Q->front->next = p->next;
    if(Q->rear == p) // 最后一个节点出队
        Q->rear= Q->front;// ! 平时rear指针在出队时是不需要动的, 但是最后一个节点出队后, rear 就变成空指针了, 有必要动一下.
    free(p);
    return true;
}

//出队(不带头结点)
bool DeQueue2(LinkQueue *Q ,Elem *e)
{
    //判空
     if(EmptyQueue2(*Q))
         return false;
     LinkNode *p = Q->front;
     *e = p->data;
     if(Q->rear == p)
     {
         Q->front = NULL;
         Q->rear = NULL;
     }
     else
        Q->front = p->next;
     free(p);
     return true;
}
int main()
{
    int *p = NULL;
    if(p)
    printf("你好");
    else
    printf("你不好");
    return 0;
}