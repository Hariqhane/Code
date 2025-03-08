#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define Maxsize 50

typedef struct SqList
{
    int data[Maxsize];
    int length;
} SqList;

//将一维数组中的两个线性表交换位置.
void Reverse(int A[], int start, int end, int len)
{
    if(start > end || end > len)
    {
        return false;
    }
    int mid = (left + right) / 2;
    for (int i = 0; i <= mid - left;i++)
    {
        int temp = A[left + i];
        A[left + i] = A[right - i];
        A[right - i] = temp;
    }
}
void exchange(int A[], int M, int N, int Len)
{
    Reverse(A, 0, M + N - 1, Len);
    Reverse(A, 0, N - 1, Len);
    Reverse(A, n, M + N - 1, Len);
}
int main()
{
    int a[10] = {1, 2, 3, 4, 5,6,7,8,9,10};
    swap(a, 10, 8, 2);
    for (int i = 0; i < 10;i++)
    {
        printf("%d\n", a[i]);
    }
        return 0;
}