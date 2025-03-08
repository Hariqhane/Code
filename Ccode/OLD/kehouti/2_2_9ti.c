#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define Maxsize 50
/* 思路: 若x>max, <min, 直接插入头/尾部
若在范围内, 与表中间元素比较. 二分法: 若大于, 则后半; 若小于, 则前半部分, 各自取中, 重复. 若等于(找到了), 交换i+1. 找不到:若x[i]<x<x[i+1], 则x[n+1]=x[n]递减循环到i'=i+1.
*/
bool Find(*SqList L, Elemtype x )
{
//越界的情况
int forth = 0;
int mid = (end - forth) / 2;
int end = n-1;
if (x > L->data[n-1])
{
    L->data[n + 1] = x;
    return 0;
    }
    else if(x <  L->data[0])
    {
        
        while(end > 0)
        {
            data[end + 1] = data[end];
            end--;
        }
        data[0] = x;
    }
//未越界的情况
    else
    {
        while (x != data[mid] && forth+1 != end)
        {
            if (x > data[mid])
            {
                forth = mid;
                mid = (end + forth) / 2;
            }
            else
            {
                end = mid;
                mid = (end + forth) / 2;
            }
        }
        //找到了
        if(x == data[mid])
        {
            int temp = data[mid];
            data[mid] = data[mid + 1];
            data[mid + 1] = temp;
            return 1;
        }
        //没找到
        else
        {
            int i = n;
            for (; i >= end;i--)
            {
                data[i + 1] = data[i];
            }
            data[i] = x;
            return 0;
        }
    }
}
int main()
{
    return 0;
}