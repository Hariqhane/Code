#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<stdbool.h>
//判断素数
bool judgePrime(int x)
{   
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
void pre_n_Prime(int n)//n以内的素数
{
    int sum = 0;
    for (int i = 2; i <= n;i++)
    {
        if(judgePrime(i))
        {
            sum++;
            printf("第%d个素数是%d\n", sum, i);
        }
    }
}
int main()
{
    // int x;
    // scanf("%d", &x);
    // pre_n_Prime(x);
    printf("中文");
    return 0;
}