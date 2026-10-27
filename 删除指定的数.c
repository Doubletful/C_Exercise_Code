#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	//题⽬描述：
	//输⼊10个整数存放在数组中后输⼊⼀个整数n，删除数组中所有等于n的数字，打印剩余的数字。

	////方法一
	//int arr[10] = { 0 };
	//int n = 0;
	////记录数组中被删除的元素个数
	//int count = 0;
	////接收存放在数组中的10个数及删除数
	//for (int i = 0; i < 10; i++)
	//{
	//	scanf("%d", &arr[i]);
	//}
	//scanf("%d", &n);
	////循环判断数组中是否存在删除数
	//for (int i = 0; i < 10; i++)
	//{
	//	if (arr[i] == n)
	//	{
	//		//定义两个指针用于从删除数的位置依次从后向前覆盖数据
	//		int* p = &arr[i];
	//		int* q = &arr[i + 1];
	//		//前移覆盖次数为数组中删除数后的元素个数
	//		for (int j = 0; j < 10 - 1 - i; j++)
	//		{
	//			*p = *q;
	//			p++;
	//			q++;
	//		}
	//		count++;
	//	}
	//}
	////打印次数为数组中未被删除的元素个数
	//for (int i = 0; i < 10 - count; i++)
	//{
	//	printf("%d ", arr[i]);
	//}
	//printf("\n");

	//方法二(优化)
	int arr[10] = { 0 };
	int n = 0;
	//接收存放在数组中的10个数及删除数
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d", &n);
	//指向下一个覆盖位置
	int j = 0;
	//循环遍历数组
	for (int i = 0; i < 10; i++)
	{
		//当前元素不等于删除数，需要使用原值覆盖(保留原值)
		if (arr[i] != n)
			//将当前元素覆盖到j指向的覆盖位置，并让j指向下一个覆盖位置
			arr[j++] = arr[i];
	}
	//打印次数为覆盖位置被更改的次数(删除后的数组长度)
	for (int i = 0; i < j; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
