#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

/*
问题描述

设有n座山，计算机与人作为比赛的双方，轮流搬山。规定每次搬山数不能超过k座，谁搬最后一座淮输。游戏开始时，计算机请人输入山的总数n和
每次允许搬山的最大数k，然后请人开始，等人输入了需要搬走的山的数目后，计算机马上打印出它搬多少座山，并提示尚余多少座山。双方轮流搬
山直到最后一座山搬完为止。计算机会显示谁是赢家，并问人是否要继续比赛。如果人不想玩了，计算机便会统计出共玩了几局，双方胜负如何。
问题分析

程序中先输入山的座数，要求每次搬山的最大数，从而找出最佳的搬山座数以获得游戏的胜利。

程序在若干次游戏结束后还记录了电脑跟人的胜负次数。程序中应用了条件语句、循环语句和逻辑判断语句来实现功能。

在有n座山的情况下，计算机为了将最后一座山留给人，而且又要控制每次搬山的数目不超过最大数k，应搬山的数目要满足关系：(n-1)%(k+1)。
算法设计

计算机参加游戏时应遵循下列原则：

(1) 当剩余山的数目-1≤可移动的最大数k时，计算机要移（剩余山数目-1）座，以便将最后一座山留给人。

(2) 对于任意正整数x，y，一定有：
0≤x%(y+1)≤y
在有n座山的情况下，计算机为了将最后一座山留给人，而且又要控制每次搬山的数目不超过最大数k，则它应搬山的数目要满足下列关系：
(n-1)%(k+1)
如果算出结果为0，即整除无余数，则规定只搬一座山，以防止冒进后发生问题。
*/

int main()
{
	int n, k, x, y, cc, pc, g;
	printf("More Mountain Game\n");
	printf("Game Begin\n");
	pc = cc = 0;
	g = 1;
	for (; ; )
	{
		printf("No.%2d game \n", g++);
		printf("-------------\n");
		printf("How many mountains are there?");
		scanf("%d", &n);  /*读入山的总数*/
		if (!n)
			break;
		printf("How many mountains are allowed to each time?");
		do
		{
			scanf("%d", &k);  /*读入允许的搬山数*/
			if (k>n || k<1)  /*判断搬山数*/
				printf("Repeat again!\n");
		} while (k>n || k<1);
		do
		{
			printf("How many mountains do you wish move away?");
			scanf("%d", &x);
			if (x<1 || x>k || x>n)  /*判断搬山数是否符合要求*/
			{
				printf("IIIegal,again please!\n");
				continue;
			}
			n -= x;
			printf("There are %d mountains left now.\n", n);
			if (!n)
			{
				printf("……………I win. You are failure……………\n\n");
				cc++;
			}
			else
			{
				y = (n - 1) % (k + 1);  /*求出最佳搬山数*/
				if (!y)
					y = 1;
				n -= y;
				printf("Copmputer move %d mountains away.\n", y);
				if (n)
					printf(" There are %d mountains left now.\n", n);
				else
				{
					printf("……………I am failure. You win………………\n\n");
					pc++;
				}
			}
		} while (n);
	}
	/*打印结果*/
	printf("Games in total have been played %d.\n", cc + pc);
	printf("You score is win %d,lose %d.\n", pc, cc);
	printf("My score is win %d,lose %d.\n", cc, pc);
	system("pause");
	return 0;
}