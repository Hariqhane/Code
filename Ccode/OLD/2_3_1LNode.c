#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct LNode
{
    int data;
    struct LNode *next; //! 指针类型错误!
} LNode, *LinkList;

LinkList HeadInsert(LinkList L)
{
    int x;
    LNode *s;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    printf("请输入:");
    scanf("%d", &x);
    while( x != 9999 )
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}
// 尾插法
LinkList TailInsert(LinkList L)
{
    int x;
    LNode *s;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    LNode *r = L;// 这里, r和L的指针指向的地址是同步的吗?
    scanf("%d", &x);
    while(x != 9999 )
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL; // 尾指针置零!
    return L;
}
/*代码封装: p->next找到第i个节点*/
bool locate(LinkList L, int i, LNode **p)
{
    int j = 0;
    *p = L;
    while (*p != NULL && j < i )
    {
        *p = (*p)->next;
        j++;
    }
    if (p == NULL) // i值不合法
        return false;
    return true;
}
/* 指定节点的前插操作*/
// 复杂度为n的方案: 由于无法直接得知待插入节点的直接前驱节点 ,需要使用locate找第i-2个节点;
// 复杂度为1的方案:
bool InsertPriorNode(LNode *p, int e)
{
    if (p == NULL) // i值不合法
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
        return false;
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}
/* 指定节点的后插操作, 其实是指定位序插入的一部分. 封装操作!*/
bool InsertNextNode(LNode *p, int e)
{
    if (p == NULL) // i值不合法
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
        return false;  // 可能会分配失败, 如内存不足
    s->data = e;       // 将新值存入
    s->next = p->next; // 新节点连旧的第i个节点
    p->next = s;       // 第i-1个节点连新的第i个节点.和上面顺序不能错, 因为被赋值的量会损失曾经的信息, s是新节点所以没有曾经的信息, 随便损失. 而旧节点不行.
    return true;
}
/*按位序插入, 带头节点*/
bool ListInsert(LinkList L, int i, int e) //!  在第i个位置插入数字e;
{
    if(i<1)
        return false;
    LNode *p;
    // 找到第i-1个节点, 将新节点插入i-1个和i个之间
    locate(L, i - 1,&p);
    return InsertNextNode(p, e);
}
/*按位序插入, 不带头结点*/
bool ListInsert_2(LinkList L, int i , int e)
{
    if (i < 1)
        return false;
    if(i == 1)
    {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = e;       // 将新值存入
        s->next = L;
        L = s;
        return true;
    }
    LNode *p;
    locate(L, i - 1, &p);
    return InsertNextNode(p, e);
}
/*指定节点的删除(输入的是待删除节点的上一个节点)*/
bool DeleteNode(LNode *p, int *e)
{
    if(p==NULL)
        return false;
    if(p->next == NULL)
        return false;
    LNode *q = p->next;//
    *e = q->data;
    p->next = q->next;
    free(q);
    return true;
}
//O1的方案:
bool DeleteNode2(LNode *p, int *e)//将删除p节点,并返回删除的节点值(输入的是待删除节点)
{
    if(p==NULL)
        return false;
    LNode *q = p->next; //q是p的后继节点
    *e = p->data;
    p->data = q->data;
    p->next = q->next; // p取代q, 成为(原来的p)的后继
    free(q);//由于p的前一个节点一直连着p, 相当于p的前驱连到了新的(p的后继)
    return true;
}   

/* 按位序删除(带头节点), 使用了locate*/
bool ListDelete(LinkList L, int i, int *e)
{
    if (i < 1)
        return false;
    LNode *p;
    // 找到第i-1个节点, 将新节点插入i-1个和i个之间
    locate(L, i - 1, &p);
    return DeleteNode(p, e);
    //or
    
    locate(L, i, &p);
    return DeleteNode2(p, e);
}
int main()
{
    LNode *L;
    HeadInsert(L);
    printf("输入结束!"); 
    return 0;
}
