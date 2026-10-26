#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	//题⽬描述：
	//输⼊y和m两个整数，y表⽰年份，m表⽰⽉份，计算y年m⽉有多少天，并输出天数。

	int y = 0;
	int m = 0;
	//存储一年每月天数的数组，默认为平年月份天数
	int arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	scanf("%d%*c%d", &y, &m);
	//输入月份是二月
	if (m == 2)
	{
		//判断是否为闰年
		if ((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0))
			printf("%d\n", arr[m - 1] + 1);
		else
			printf("%d\n", arr[m - 1]);
	}
	else
		printf("%d\n", arr[m - 1]);

	return 0;
}
