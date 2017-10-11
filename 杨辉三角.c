#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define N 14

int main()
{
	int a[N][N] = {0}, i, j, k, n = 0;
	while (n <= 0 || n >= 13)
	{
		printf("请输入杨辉三角的行数：");
		scanf("%d", &n);
	}
	for (i = 0; i < n; i++)
	{
		a[i][0] = a[i][i] = 1;
		
		if (i > 1)
		{
			for (j = 1; j < i; j++)
			{
				a[i][j] = a[i - 1][j] + a[i - 1][j - 1];				
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i+1; j++)
		{
			printf("%6d", a[i][j]);
		}
		printf("\n");
	}
	
	system("pause");
	return 0;
}

