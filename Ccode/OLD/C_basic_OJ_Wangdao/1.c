#include <stdio.h>
int main()
{
	int cnt = 0;
	for(int i = 1;i<5;i++)
	{
		for(int j = 1 ;j<5;j++)
		{
			if(i == j)
				continue;
			for(int k = 1 ;k < 5; k++)
			{
				if( j == k||i ==k )
				continue;
				else
				{
					cnt++;
					printf("第%d个数字是%d\n",cnt,100*i+10*j+k);
				}
			}
		}
	}
}