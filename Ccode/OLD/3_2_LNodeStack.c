#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define Elem int

// 定义链表节点结构体
typedef struct LinkNode
{
    Elem data;
    struct LinkNode *next;
} LinkNode, *LiStack; // LinkNode 作为节点，LiStack 作为指向节点的指针，即栈顶指针

// 初始化栈
void Init_LiStack(LiStack *s)
{
    *s = NULL; // 初始化栈为空
}

// 入栈操作
bool Push(LiStack *s, Elem x)
{
    LinkNode *new_node = (LinkNode *)malloc(sizeof(LinkNode));
    if (new_node == NULL)
        return false; // 内存分配失败
    new_node->data = x;
    new_node->next = *s; // 新节点指向当前栈顶
    *s = new_node;       // 更新栈顶为新节点
    return true;
}

// 出栈操作
bool Pop(LiStack *s, Elem *e)
{
    if (*s == NULL)
        return false;    // 栈为空，出栈失败
    *e = (*s)->data;     // 返回栈顶元素
    LinkNode *temp = *s; // 临时保存栈顶节点
    *s = (*s)->next;     // 更新栈顶
    free(temp);          // 释放原栈顶节点
    return true;
}

// 获取栈顶元素
bool GetTop(LiStack *s, Elem *x)
{
    if (*s == NULL)
        return false; // 栈为空
    *x = (*s)->data;  // 返回栈顆元素
    return true;
}

int main()
{
    LiStack s;
    Init_LiStack(&s); // 初始化栈

    Push(&s, 10);
    Push(&s, 20);

    Elem top;
    if (GetTop(&s, &top))
    {
        printf("栈顶元素是: %d\n", top);
    }

    Elem popped;
    if (Pop(&s, &popped))
    {
        printf("弹出的元素是: %d\n", popped);
    }

    if (GetTop(&s, &top))
    {
        printf("新的栈顶元素是: %d\n", top);
    }

    return 0;
}
