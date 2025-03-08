// 定义一个顺序表.
#include <stdio.h>
#include <stdbool.h> // True-
#include <stdlib.h>  //malloc-free
#include <string.h>  //string function
//! 静态分配
#define Maxsize 50 // 定义线性表的最大长度
typedef struct
{
    int length;        // 顺序表当前长度;
    int data[Maxsize]; // 表的类型可改;
} SqList;              // 用typedef定义为SqList;

//! 动态分配
#define InitSize 100; // 表长度的初始定义;
typedef struct
{
    int *data;            // 指示动态分配数组的指针;
    int Max_size, length; // 数组的最大长度和当前个数
} SeList;

void InitListSq(SqList *L) // 初始化静态表
{
    L->length = 0;
}

void InitListSe(SeList *L) // 初始化动态表
{
    L->length = 0;
}

void InitListSq2(SqList *L) // 输入静态表
{
    int len;
    scanf("%d", &len);
    L->length = len;
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &L->data[i]);
    }
}

void InitListSe2(SeList *L)
{
    int len;
    scanf("%d", &len);
    if (L->data != NULL)
    {
        free(L->data); // 先释放已有的内存
    }
    L->data = (int *)malloc(len * sizeof(int));
    if (L->data == NULL)
    {
        printf("内存分配失败。\n");
        return; // 如果内存分配失败，则直接返回
    }
    L->length = len;
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &L->data[i]);
    }
}

int Length(SqList L)
{
    return L.length;
}
bool ListInsert(SqList *L, int i, int e) // L: 传入的表指针;i: 插入的位置(1开始数);e: 要插入的数值
{
    if (i < 1 || i > L->length + 1)
        return false;
    if (L->length >= Maxsize)
        return false; // 两种情况不合法: 插入位置大于表长或小于1;插入后表数据溢出
    for (int j = L->length; j >= i; j--)
        L->data[j] = L->data[j - 1];
    L->data[i - 1] = e;
    L->length++;
    return true;
}

bool ListDelete(SqList *L, int i, int *e)
{
    if (i < 1 || i > L->length) // 判断i的范围是否有效;
        return false;
    *e = L->data[i - 1];               // 将被删除的元素赋值给e;注意和插入的区别
    for (int j = i; j < L->length;j++)
        L->data[j - 1] = L->data[j];

    L->length--; // 线性表长度-1;
    return true;
}
int main()
{
    //初始化Sq测试
    // SqList list1;
    // SqList *listq = &list1;
    // InitListSq(listq);
    // InitListSq2(listq);
    // printf("%d",Length(list1));

    //初始化Se测试
    // SeList list2;
    // InitListSe(&list2);
    // InitListSe2(&list2);

    //删除测试
    // SqList myList = {5, {1, 2, 3, 4, 5}};
    // int deletedElement;
    // if (ListDelete(&myList, 3, &deletedElement))
    // {
    //     printf("Deleted element: %d\n", deletedElement);
    //     printf("New length: %d\n", myList.length);
    //     // 打印剩余元素，验证删除操作
    //     for (int i = 0; i < myList.length; i++)
    //     {
    //         printf("%d ", myList.data[i]);
    //     }
    //     printf("\n");
    // }
    // else
    // {
    //     printf("Invalid position!\n");
    // }


    return 0;
}
