#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	//题⽬描述：
	//输⼊10个整数，然后使⽤冒泡排序对数组内容进⾏升序排序，然后打印数组的内容

	//存放输入值
	int arr[10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	//冒泡排序
	for (int i = 0; i < 10 - 1; i++)
	{
		//判断数组升序标志
		int flag = 1;
		for (int j = 0; j < 10 - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				//非升序更改标志
				flag = 0;
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		if (flag)
		{
			break;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;

}
