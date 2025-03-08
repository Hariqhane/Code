#include <stdio.h>
int main()
{
    int num = 0;
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 20; j++)
        {
            for (int k = 1; k < 40-i-j; k++)
            {
                if (10 * i + 5 * j + 2 * k + 40 - i - j - k == 100 && 40-i-j-k >0)
                {
                    num++;
                    printf("换法%d:%d个10,%d个5,%d个2,%d个1\n", num, i, j, k,40-i-j-k);
                }
            }
        }
    }
    printf("%d", num);
    return 0;
}
