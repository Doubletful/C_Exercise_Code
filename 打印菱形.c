#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	//题⽬描述：
	//输⼊⼀个整数n，使用*打印对应2 * n - 1⾏的菱形图案

	int n = 0;
	scanf("%d", &n);
	//先打印上n - 1行，再打印下n行
	//控制上菱形打印(2 * n - 1 = n - 1 + n)
	for (int i = 0; i < n - 1; i++)
	{
		//控制一行打印的空格(n - 1至1)
		for (int j = 0; j < n - 1 - i; j++)
		{
			printf(" ");
		}
		//控制一行打印的符号(1至1 + 2 * (n - 2))
		for (int j = 0; j < 1 + 2 * i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	//控制下菱形打印(2 * n - 1 = n - 1 + n)
	for (int i = 0; i < n; i++)
	{
		//控制一行打印的空格(0至n - 1)
		for (int j = 0; j < i; j++)
		{
			printf(" ");
		}
		//控制一行打印的符号(2 * n - 1至1)
		for (int j = 0; j < 2 * n - 1 - i * 2; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;

}
