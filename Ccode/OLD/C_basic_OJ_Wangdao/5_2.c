#include <stdio.h>
#include <stdlib.h> //malloc-free
#include <string.h> //string function
// 怎么检验字符串为空?
// 一个字符数组, 怎么检测字符串不为空的长度是多少?
int main()
{
    int LEN = 20;
    char a[LEN];
    // for (int i = 0; i < LEN - 1; i++)
    // {
    //     a[i] = '@';
    // }
    // // for (int i = 0; i < LEN - 1; i++)
    // // {
    // //     printf("%c\n", a[i]);
    // // }

    // char temp;
    // int cnt = -1; // 因为\0会被算进去一个
    gets(a);
    // for (int i = 0; i < 20; i++)
    // {
    //     if (a[i] == '@')
    //         break;
    //     cnt++;
    // }
    int len = strlen(a);
    char back[len+1];
    // printf("字符串长度为%d\n", cnt);
    // printf("strlen:%d", strlen(a));
    for (int i = 0; i <=len ; i++)
    {
        back[len - 1 - i] = a[i];
        // a[i] = a[cnt - 1 - i];
        // a[cnt - 1 - i] = temp;
    }
    // printf("%s\n", a);
    // printf("%s\n", back);
    int result = strcmp(a,back);
    // printf("%d", result);
    if (result < 0)
    {
        printf("%d\n", -1);
    }
    if (result == 0)
    {
        printf("%d\n",0);
    }
    if (result > 0)
    {
        printf("%d\n", 1);
    }
    return 0;
}
