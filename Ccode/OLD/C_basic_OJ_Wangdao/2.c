#include <stdio.h>
int main()
{
    int cnt = 0;
    int opnum = 0;
    for (int i = 0; i < 83; i++)
    {
        for (int j = i; j <= 83; j++)
        {
            if (i * i + 168 == j * j)
            {
                cnt++;
                printf("第%d个数是%d\n", cnt, i * i - 100);
            }
            opnum++;
        }
        opnum++;
    }
    printf("循环次数为%d", opnum);
    return 0;
}