#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	//输入一个整数n，使用*打印对应n行的X型图案

	int n = 0;
	scanf("%d", &n);
	//打印行
	for (int i = 0; i < n; i++)
	{
		//打印列
		for (int j = 0; j < n; j++)
		{
			//对角线打印*，打印正对角线判断条件，打印反对角线判断条件
			if (i == j || j == n - 1 - i)
				printf("*");
			else //除对角线外打印空格
				printf(" ");
		}
		printf("\n");
	}

	return 0;
}
