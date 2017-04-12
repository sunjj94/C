#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, k, sum=0, d;
	printf("请输入山的总数和每次允许搬山的最大数：\n");
	scanf("%d %d", &n, &k);
	printf("请输入你将要搬走的山的数目,必需小于 %d ：\n", k);
	scanf("%d", &d);
	if (sum > n)
	{
		printf("游戏结束");
		return 0;
	}
	while (1)
	{		
		if (d > k || d > (n - sum))
		{
			while (d > k || d > (n - sum))
			{
				printf("您输入的搬山数不符合规定，请重输：\n");
				scanf("%d", &d);
			}
		}
		if (d < k || d == k)
		{
			sum += d;				
			printf("还剩余 %d 座山\n", n-sum);
			if (sum < n)
			{
				if ((n-sum) < k)
					printf("请输入你将要搬走的山的数目, 必需小于 %d ：\n", n - sum);
				else
					printf("请输入你将要搬走的山的数目, 必需小于 %d ：\n", k);
				scanf("%d", &d);
			}
			if (!(sum < n))
			{
				printf("游戏结束\n");
				break;
			}
		}					
	}	
	system("pause");
	return 0;
}