#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define Maxsize 50
typedef struct
{
    int length;
    int data[Maxsize];
}SqList;

#define InitSize 100;
typedef struct
{
    int *data;
    int Max_size, length;
}SeList;
//初始化静态表
void InitList(SqList *L)
{
    L->length = 0;
}

void InitList2(SqList *L)
{
    int len;
    scanf("%d", &len);
    for (int i = 0; i < len;i++)
    {
        scanf("%d", &L->data[i]);
        L->length = len;
    }
}
//初始化动态表
void InitListSe(SeList *L)
{
    L->length = 0;
}

void InitListSe2(SeList *L)
{
    int len;
    scanf("%d", &len);
    if(L->data !=NULL)
    {
        free(L->data);
    }
    L->data = (int *)malloc(sizeof(int) * len);
    if(L->data == NULL)
    {
        printf("内存分配失败.\n");
        return;
    }
    L->length = len;
    for (int i = 0; i < len;i++)
    {
        scanf("%d", &L->data[i]);
    }
}
//求表长
int Length(SqList L)
{
    return L.length;
}
//插入
bool ListInsert(SqList *L, int i, int e)
{
    if( i <1||i>L->length+1)
        return false;
    if (L->length >= Maxsize)
        return false;
    for (int j = L->length; j >= i; j--)
    {
        L->data[j] = L->data[j-1];
    }
    // for (int j = i; j <= L->length;j++)
    // {
    //     L->data[j] = L->data[j-1];
    // }
    for (int j = 0; j < L->length - i + 1; j++)
    {
        L->data[L->length - j] = L->data[L->length - j - 1];
    }
        L->data[i - 1] = e;
    L->length += 1;
    return true;
}
//删除
bool ListDelete(SqList*L, int i, int *e)
{
    if(i<1||i>L->length)
        return false;
    *e = L->data[i-1];
    for (int j = i; j < L->length;j++)
    {
        L->data[j - 1] = L->data[j];
    }
    L->length--;
    return true;
}
// 按值查找
int LocateElem(SqList *L, int e)
{
    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i] == e) // 比较值而非指针
            return i + 1;    // 返回匹配的元素的位置，位置基于1
    }
    return 0; // 如果未找到匹配的元素，返回0
}

// 按位查找
int LocateLocation(SqList *L, int i)
{
    if (i < 1 || i > L->length)
        return -1; // 使用-1表示查找失败，更加常见且一致
    else
        return L->data[i - 1]; // 修正索引，从0开始计数
}
//销毁动态表(静态表不需要也不能销毁)
void DestoryList(SeList *L)
{
    free(L->data);  // 释放内存;
    L->data = NULL; // 将表头指针指向NULL, 避免野指针;
    L->length = 0;  // 表长度置0;
    L->Max_size = 0;// 表容量置零;
}
int main()
{
    SqList L;
    printf("正在初始化1...\n");
    InitList(&L);
    printf("初始化完成! 现在表长为%d\n", L.length);
    printf("接下来请输入表的长度:");
    InitList2(&L);
    printf("没错, 表的长度为%d\n", Length(L));
    int i = 2;
    int e = 50;
    printf("接下里将在第%d个位置插入值%d\n", i, e);
    ListInsert(&L,i,e);
    printf("插入的值为:%d\n", L.data[i - 1]);
    int *E;
    ListDelete(&L, i+1, E);
    printf("删除的位置为%d, 值为%d\n", i, *E);

    printf("接下来是按值查找.\n");
    if (LocateElem(&L, 1)!= 0)
    {
        printf("1在第%d个位置\n", LocateElem(&L, 1));
    }
    else
        printf("对不起找不到\n");
        return 0;
    //函数会先被编译吗?会的
}