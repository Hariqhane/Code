#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define Elem int
#define maxsize 50
// //静态顺序表的定义
//     typedef struct SqList
//     {
//         Elem data[maxsize];
//         int length;
//     } SqList;
//     // 静态顺序表的初始化
//     void init_SqList(SqList *q)
//     {
//         q->length = 0;
//     }
//     //插入, 删除
//     bool ins_Sq(SqList *q, Elem e, int i)
//     {
//         if(q->length>=maxsize)
//             return false;
//         else
//         {
//         // init: length = length-1;
//         //end: i = i-1

//             for (int n = q->length; n >= i;n--)
//             {
//                 q->data[n] = q->data[n - 1];
//             }
//             q->data[i - 1] = e;
//             q->length += 1;
//             return true;
//         }
//     }
//     bool del_Sq(SqList *q, int i, Elem e)
//     {
//         if(q->length = 0)
//             return false;
//         else
//         {
//             // init: i-1 = i;
//             // end: length-2 = length-1;

//             for (; i < q->length - 1;i++)
//             {
//                 q->data[i - 1] = q->data[i];
//             }
//             q->length -= 1;
//             return true;
//         }
//     }
//     //按值查找, 按位查找
//     int find_value(SqList q,Elem e)
//     {
//         for (int n = 0; n < q.length;n++)
//         {
//             if(q.data[n] == e)
//             {
//                 return n;
//             }
//             else
//                 return 0;
//         }
//     }
//     //输出表的所有值
//     void Sq_print(SqList q)
//     {
//         for (int i = 0; i < q.length;i++)
//         {
//             printf("表的第%d个数字是%d\n", i, q.data[i]);
//         }
//     }
// //动态表
// typedef struct SeList
// {
//     int length;
//     Elem *data;
// } SeList;
// /*动态表的初始化
// 若data置于NULL
// */

// void init_Se(SeList *q)
// {
//     if(q->data != NULL)
//     {
//         free(q);
//         q->data = NULL;
//     }
//     q->length = 0;
// }
// // 单链表, 创建
// typedef struct LNode
// {
//     Elem data;
//     struct LNode *next;
// } LNode, *LinkList;
// //单链表, 头插法
// LinkList HeadInsert_withHeadNode(LNode *L)
// {

//     int x = 0;
//     L = (LinkList)malloc(sizeof(LNode));
//     L->next = NULL; // 头结点的next指向NULL;
//     LNode *q;//新的链表节点
//     //! LNode *HP = L; 有头结点就不需要头指针了
//     scanf("%d", &x);
//     while(x!= 9999)
//     {
//         q = (LinkList)malloc(sizeof(LNode));
//         q->data = x;
//         q->next = L->next;
//         L->next = q;
//     }
//     return L;
// }
// //单链表, 无头结点的头插法
// LinkList HeadInsert_noHeadNode(LinkList L)
// {
//     // !L = NULL; 这里是错误的, 因为每次调用这个函数都会让头结点被丢弃,

//     LNode *p;
//     int x;
//     scanf("%d", &x);
//     while(x!=9999)
//     {
//         p = (LinkList)malloc(sizeof(LNode));
//         p->data = x;
//         p->next = L;
//         L = p;
//     }
// }
// //单链表, 尾插法
// LinkList TailInsert(LinkList L)
// {
//     int x;//数据域
//     LNode *q; // 新节点;
//     L = (LinkList)malloc(sizeof(LNode));//
//     LNode *tail = L;
//     scanf("%d", &x);
//     while(x!=9999)
//     {
//         q = (LinkList)malloc(sizeof(LNode));
//         q->data = x;
//         tail->next = q;
//         tail = q;
//         scanf("%d", &x);
//     }
//     tail->next = NULL; // 尾指针指向NULL表示链表结束;
//     return L;
// }
// //按序号查找节点, 有头结点
// LNode *GetNode(LinkList L, int i )
// {
//     LNode *Aim = L;
//     if(i<1||L == NULL)
//         return NULL;
//     else
//     {
//         for(int n = 0; n < i;n++)
//         {
//             Aim = Aim->next;
//             if(Aim == NULL)// 检查是否越界
//                 return NULL;
//         }
//         return Aim;
//     }
// }
// //按值查找, 有头结点
// LNode *GetNode_value(LinkList L, Elem i)
// {
//     LNode *Aim = L->next;
//     if(L==NULL)
//         return NULL;//表空
//     else
//     {
//         while (Aim != NULL && Aim->data != i)
//         {
//             if(Aim->data != i)
//             {
//                 Aim = Aim->next;
//             }
//             else
//                 return Aim;
//         }
//         return NULL;//超出表长
//     }
// }
// //单链表插入, 有头结点
// //指定位置插入制定节点? 
// //指定位置添加新节点
// bool Insert_LinkList(LinkList L, int i, Elem e)
// {
//     if(i<1||L ==NULL)
//         return false;
//     LNode *newNode;
//     LNode *Nowpoint = L;
//     //Nowpoint指向第i-1个节点
//     for (int k = 0; Nowpoint!=NULL && k < i - 1;k++){
//         Nowpoint = Nowpoint->next;
//     }
//     if(Nowpoint == NULL)
//         return false;
//     newNode = (LNode *)malloc(sizeof(LNode));
//     if(newNode == NULL)
//         return false;
//     newNode->data = e;
//     newNode->next = Nowpoint->next;
//     Nowpoint->next = newNode;
//     return true;
// }
// //在指定节点前方插入
// bool preinsert_withHeadNode(LNode *p, Elem e)
// {
//     if(p == NULL)
//         return false;
//     LNode *NewNode;
//     NewNode = (LNode *)malloc(sizeof(LNode));
//     if(NewNode == NULL)
//         return false;
//     NewNode->next = p->next;
//     p->next = NewNode;
//     NewNode->data = p->data;
//     p->data = e;
//     return true;
// }
// //删除指定节点
// bool del_Node(LNode *aim, Elem *e)
// {
//     // if(L->next == NULL)//没有这个节点怎么办?
//     LNode *q = aim->next;
//     if(aim ==NULL||q==NULL)
//         return false;
//     *e = aim->data;
//     Elem x_temp = aim->next->data;

//     aim->next = aim->next->next;
//     aim->data = x_temp;
//     free(q);
//     if(q==NULL)
//         return true;
//         //只能遍历了
//     return true;
// }
// //双链表节点的定义
// typedef struct DLNode
// {
//     Elem data;
//     struct DLNode *prior;
//     struct DLNode *next;
// } DLNode,*DLinkList;
// //双链表的初始化
// DLinkList Init_DLinkList(DLinkList L)
// {
//     L = (DLNode *)malloc(sizeof(DLNode));
//     L->prior = NULL;
//     L->next = NULL;
//     return L;
// }
// // 双链表指定节点前插入
// // 前插: 不用担心开头, 因为会有头结点; 因为是前插, 故末尾也不担心. 但是这样无法将节点插入为最后一个节点.
// //若为后插, 就要担心末尾问题了.
// bool Insert_DLinkList(DLNode *p, Elem e)
// {
//     if(p == NULL)
//         return false;
//     // if(p->prior == NULL)
//     DLNode *q = (DLNode *)malloc(sizeof(DLNode));
//     q->prior = p->prior;
//     q->next = p;
//     p->prior->next = q;
//     p->prior = q;
//     return true;
// }
// ///!栈
// typedef struct 
// //顺序栈
// //!栈的相关操作
// //初始化
// //判栈空
// //进栈
// //出栈
// //读栈顶元素
// //链栈
// //!队列
// //顺序存储
// //队列的相关操作
// //循环队列
// //初始化
// //判队空
// //入队
// //出队
// //队列的链式存储
// //链队的基本操作
// //初始化
// //判队空
// //入队
// //出队
// //双端队列


// //串
// //KMP算法
// //树

// //图

int main()
{
    printf("你好");
    return 0;
}
