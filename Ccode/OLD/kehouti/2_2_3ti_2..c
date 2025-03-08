#include <stdio.h>
#include <stdbool.h>
#define Maxsize 50
typedef struct SqList
{
    int length;
    int data[Maxsize];
} Sq;
void Reverse(Sq *L)
{
    int a;
    for (int i = 0; L->length -1-2* i >0;i++)
    {
        a = L->data[L->length - 1 - i];
        L->data[L->length - 1 - i] = L->data[i];
        L->data[i] = a;
    }
    printf("逆转结束!\n");
}
int main()
{
    return 0;
}
