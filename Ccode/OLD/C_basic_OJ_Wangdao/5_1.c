#include <stdio.h>
int main()
{
    int a[100];
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num;i++)
    {
        scanf("%d",&a[i]);
    }
    int cnt = 0;
    for (int i = 0; i < num;i++)
    {
        if(a[i] == 2)
            cnt++;
    }
    printf("%d", cnt);
    return 0;
}