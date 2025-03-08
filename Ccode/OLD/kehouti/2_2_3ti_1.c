// 删元素 , 代码综合题2.1
#include <stdio.h>
#include <stdbool.h>

#define Maxsize 50
typedef struct SqList
{
    int  length;
    int data[Maxsize];
} SqList;
int min_of_List(int *L,int len, int *e)
{
    
    *e = 0;
    int temp = L[0];
    for (int i = 1; i < len; i++)
    {
        if (temp > L[i])
        {
            temp = L[i];
            *e = i;
        }
    }

    return temp;
}

int Delete_min(SqList *L)
{
    int i,min;
    if(L->length == 0)
    {
        printf("删除失败, 表是空的");
    }
    else
    {
        min =min_of_List(L->data, L->length,&i);
        L->data[i] = L->data[L->length-1];
        L->length -= 1;
        return min;
    }
}
bool Del_min(SqList *L, int *value)
{
    if(L->length == 0)
        return false;
    *value = L->data[0];
    int pos = 0;
    for (int i = 1; i < L->length;i++)
    {
        if(L->data[i]<*value)
        {
            *value = L->data[i];
            pos = i;
        }
    }
    L->data[pos] = L->data[L->length - 1];
    L->length--;
    return true;
}
int main()
{
    int a = 0;
    SqList L = {5,{5,1,4,8,7}};
    // printf("顺序表最小值为%d\n", Delete_min(&L));
    Del_min(&L, &a);
    printf("%d", a);
    return 0;
}

