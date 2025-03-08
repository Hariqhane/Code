#include <stdio.h>
int main()
{
    int n;
    
    scanf("%d", &n);
    int mul = 1;
    for (; n > 1;n--)
    {
        mul *= n;
    }
    printf("%d", mul);
    return 0;
}