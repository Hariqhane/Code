#include <stdio.h>
int digui(int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }
    else if( n < 0)
    {
        return 0;
    }
    else
    {
        return digui(n - 1) + digui(n - 2);
    }

    
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", digui(n));
    return 0;
}
