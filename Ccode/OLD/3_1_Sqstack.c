// 栈的初始化
#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define Maxsize 10
#define Elemtype int

typedef struct LinkNode
{
    Elemtype data;
    struct LinkNode *next;
}LiNodeStack,*LiStack;

//初始化栈
void InitStack(LiStack S)
{
    S = NULL;//这个就是头指针
}
// 增加一个链栈节点;
bool Push_LinkNode(LiStack S, Elemtype x)
{
    LiStack s = (LiStack)malloc(sizeof(LiNodeStack));
    S->data = x;
}

int main()
{
    
    return 0;
    
}
