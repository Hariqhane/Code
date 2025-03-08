#include <stdio.h>
#include <stdlib.h>
/*思路1: 把整个数倒转, 如果不变则为对称数.
思路2: 把所有数都取出来, 记录位数, 建立数组, 然后比较a[i]和a[len-i]

*/

int main()
{
    int i, orgin;
    scanf("%d", &i);
    orgin = i;
    int cet = 0;
    while (i != 0)
    {
        cet = cet * 10 + i % 10;
        i /= 10;
    };
    if( cet == orgin)
    {
        printf("yes");
    }
    else
        printf("no");
    return 0;
}