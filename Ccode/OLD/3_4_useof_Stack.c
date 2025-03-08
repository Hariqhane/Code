#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define Maxsize 50
typedef struct Stack
{
    char data[Maxsize];
    int top;
} SqStack;

void InitStack(SqStack *S)
{
    S->top = -1;
}
bool Push(SqStack *S, char s)
{
    if (S->top == Maxsize - 1)
    {
        return false;
    }
    S->top++;
    S->data[S->top] = s;
    return true;
}

bool Pop(SqStack *S, char *e)
{
    if (S->top == -1)
        return false;
    *e = S->data[S->top];
    S->top--;
    return true;
}
bool StackEmpty(SqStack S)
{
    return S.top == -1;
}
bool bracketCheck(char str[], int length)
{

    SqStack S;
    InitStack(&S);
    for (int i = 0; i < length; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            Push(&S, str[i]);
        }
        else
        {
            if (StackEmpty(S))
                return false; // 匹配到右括号且当前栈空

            char topElem;
            Pop(&S, &topElem);
            if (str[i] == ')' && topElem != '(')
                return false;
            if (str[i] == ']' && topElem != '[')
                return false;
            if (str[i] == '}' && topElem != '{')
                return false;
        }
    }
    return StackEmpty(S);
}
int main()
{
    int length;
    char str[Maxsize];
    printf("请输入长度:");
    scanf("%d", &length);
    
    int i = 0;
    while(i < length)
    {
        scanf(" %c", &str[i]);
        if (str[i] != '(' && str[i] != ')' && str[i] != '[' && str[i] != ']' && str[i] != '{' && str[i] != '}')
        {
            printf("输入错误,请重新输入");
            continue;
        }
        i++;
    }
    

    if (bracketCheck(str, length))
    {
        printf("Success\n");
    }
    else
    {
        printf("False\n");
    }
    return 0;
}