#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

int main8()
{
	//题⽬描述:
	//输⼊10个整数，写代码找出其中最⼤值和最⼩值，计算最⼤值和最⼩值的差，并打印出差值结果
	
	//方法一
	//存放输入值
	int arr[10] = { 0 };
	//循环接收输入
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	//假定最大与最小值
	int max = arr[0];
	int min = arr[0];
	//依次遍历比较更新最大与最小值
	for (int i = 0; i < 10; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
		if (min > arr[i])
		{
			min = arr[i];
		}
	}
	//计算最大值与最小值的差
	printf("%d\n", max - min);

	//方法二
	int num = 0;
	scanf("%d", &num);
	//假定最大值与最小值
	int Max = num;
	int Min = num;
	//依次比较每次的输入值更新最大与最小值
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &num);
		if (Max < num)
		{
			Max = num;
		}
		if (Min > num)
		{
			Min = num;
		}
	}
	//计算最大值与最小值的差
	printf("%d\n", max - min);

	return 0;

}
