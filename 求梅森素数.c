#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int prime(int n)
{
	int k, i;
	if (n == 2)
		return 1;
	else
	{
		k = sqrt(n) + 1;
		for (i = 2; i <= k; i++)
		{
			if (n % i == 0)
				return 0;
		}
	}	
	return 1;
}


int main()
{
	int i, p;
	for (i = 2; i < 21; i++)
	{
		if (prime(i))
		{
			p = pow(2, i) - 1;
			if (prime(p))
				printf("%d ", p);
		}		
	}
	system("pause");
	return 0;
}