#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct LNode
{
    int data;
    struct LNode *next; //! 指针类型错误!
} LNode, *LinkList;
