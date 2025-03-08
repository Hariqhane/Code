#include <stdio.h>
#include <stdlib.h> //malloc-free
// #include <string.h> //string function

int main()
{
    int num;
    char *str;
    scanf("%d", &num);
    // fflush(stdin);
    while (getchar() != '\n'); // 清除输入缓冲区中的换行符
    str = (char *)malloc((num+1) * sizeof(char));
    
    fgets(str, num + 1, stdin);
    // scanf("%s", str);
    printf("%s", str);
    free(str);
    return 0;
}