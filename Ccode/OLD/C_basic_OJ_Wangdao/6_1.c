#include <stdio.h>
// #include <stdlib.h> //malloc-free
// #include <string.h> //string function
void change(int i)
{
    printf("%d", i / 2);
}
int main()
{
    int i;
    scanf("%d", &i);
    change(i);
    return 0;
}